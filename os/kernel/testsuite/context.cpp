/*
 * Copyright 2008, 2009 Google Inc.
 * Copyright 2006 Nintendo Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string.h>
#include <es.h>
#include <es/context.h>
#include "core.h"

#define NumOf(x)        (sizeof(x)/sizeof((x)[0]))
#define TEST(exp)                           \
    (void) ((exp) ||                        \
            (esPanic(__FILE__, __LINE__, "\nFailed test " #exp), 0))

class Foo : public IInterface
{
    int ref;

public:
    Foo() : ref(1)
    {
    }

    ~Foo()
    {
    }

    void* queryInterface(const char* riid)
    {
        void* objectPtr;
        if (strcmp(riid, IInterface::iid()) == 0)
        {
            objectPtr = static_cast<IInterface*>(this);
        }
        else
        {
            return NULL;
        }
        static_cast<IInterface*>(objectPtr)->addRef();
        return objectPtr;
    }

    unsigned int addRef()
    {
        return ++ref;
    }

    unsigned int release()
    {
        if (--ref == 0)
        {
            delete this;
        }
        return ref;
    }
};

static bool IsNameInList(const char** namelist, int num, const char* name)
{
    while (0 < num)
    {
        if (strcmp(namelist[num-1], name) == 0)
        {
            return true;
        }
        --num;
    }
    return false;
}

static int test_without_smart_pointer(IContext* context)
{
    IIterator* iterator;
    char name[64];
    IBinding* binding;
    IInterface* unknown;
    Foo foo;

    binding = context->bind("a", &foo);
    binding->release();
    binding = context->bind("b", &foo);
    binding->release();

    IContext* sub = context->createSubcontext("sub");
    sub->release();
    binding = context->bind("sub/d", &foo);
    binding->release();

    unknown = context->lookup("sub/d");
    TEST(unknown == static_cast<IInterface*>(&foo));
    unknown->release();

    const char* namelist[] =
    {
        "a",
        "b",
        "sub"
    };
    int numName = 0;

    iterator = context->list("");
    while (iterator->hasNext())
    {
        unknown = iterator->next();
        binding = reinterpret_cast<IBinding*>(unknown->queryInterface(IBinding::iid()));
        unknown->release();
        binding->getName(name, sizeof name);
#ifdef VERBOSE
        esReport("%s\n", name);
#endif // VERBOSE
        binding->release();

        TEST(IsNameInList(namelist, NumOf(namelist), name));
        ++numName;
    }
    iterator->release();

    TEST(numName == NumOf(namelist));

    // check destroySubcontext(), rename() and unbind().
    sub = context->createSubcontext("sub2");
    sub->release();
    context->destroySubcontext("sub2");

    context->rename("a", "c");
    context->unbind("c");

    const char* namelist2[] =
    {
        "b",
        "sub"
    };

    numName = 0;
    iterator = context->list("");
    while (iterator->hasNext())
    {
        unknown = iterator->next();
        binding = reinterpret_cast<IBinding*>(unknown->queryInterface(IBinding::iid()));
        unknown->release();
        binding->getName(name, sizeof name);
#ifdef VERBOSE
        esReport("%s\n", name);
#endif // VERBOSE
        binding->release();
        iterator->remove();

        TEST(IsNameInList(namelist, NumOf(namelist), name));
        ++numName;
    }
    iterator->release();

    TEST(numName == NumOf(namelist2));

    return 0;
}

static int test_with_smart_pointer(IContext* _context)
{

    char name[64];
    Foo foo;
    Handle<IBinding> binding;

    Handle<IContext> context(_context, true);
    binding = context->bind("a", &foo);
    binding = context->bind("b", &foo);

    Handle<IContext> sub = context->createSubcontext("sub");
    binding = context->bind("sub/d", &foo);

    const char* namelist[] =
    {
        "a",
        "b",
        "sub"
    };

    int numName = 0;
    Handle<IIterator> iterator = context->list("");
    while (iterator->hasNext())
    {
        binding = iterator->next();
        binding->getName(name, sizeof name);

        TEST(IsNameInList(namelist, NumOf(namelist), name));
        ++numName;
    }

    TEST(numName == NumOf(namelist));
    iterator = 0;

    // check destroySubcontext(), rename() and unbind().
    Handle<IContext> sub2 = context->createSubcontext("sub2");
    context->destroySubcontext("sub2");

    context->rename("a", "c");
    context->unbind("c");

    const char* namelist2[] =
    {
        "b",
        "sub"
    };

    numName = 0;
    iterator = context->list("");
    while (iterator->hasNext())
    {
        binding = iterator->next();
        binding->getName(name, sizeof name);
#ifdef VERBOSE
        esReport("%s\n", name);
#endif // VERBOSE
        iterator->remove();

        TEST(IsNameInList(namelist2, NumOf(namelist2), name));
        ++numName;
    }
    TEST(numName == NumOf(namelist2));

    return 0;
}

int main()
{
    IInterface* root = NULL;
    esInit(&root);
    IContext* context;

    int ret;
    context = new Context;
    ret = test_without_smart_pointer(context);
    context->release();
    if (ret < 0)
    {
        return 1;
    }

    context = new Context;
    ret = test_with_smart_pointer(context);
    context->release();
    if (ret < 0)
    {
        return 1;
    }

    esReport("done.\n");
    return 0;
}
