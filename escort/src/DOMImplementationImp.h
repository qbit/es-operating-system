/*
 * Copyright 2010-2012 Esrille Inc.
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

#ifndef DOMIMPLEMENTATION_IMP_H
#define DOMIMPLEMENTATION_IMP_H

#include <Object.h>
#include <org/w3c/dom/DOMImplementation.h>
#include <org/w3c/dom/css/CSSStyleSheet.h>
#include <org/w3c/dom/DOMException.h>
#include <org/w3c/dom/Document.h>
#include <org/w3c/dom/DocumentType.h>

namespace org { namespace w3c { namespace dom { namespace bootstrap {

class DOMImplementationImp : public ObjectMixin<DOMImplementationImp>
{
    css::CSSStyleSheet defaultCSSStyleSheet;
    css::CSSStyleSheet userCSSStyleSheet;

public:
    DOMImplementationImp();

    css::CSSStyleSheet getDefaultCSSStyleSheet() {
        return defaultCSSStyleSheet;
    }
    void setDefaultCSSStyleSheet(css::CSSStyleSheet sheet) {
        defaultCSSStyleSheet = sheet;
    }

    css::CSSStyleSheet getUserCSSStyleSheet() {
        return userCSSStyleSheet;
    }
    void setUserCSSStyleSheet(css::CSSStyleSheet sheet) {
        userCSSStyleSheet = sheet;
    }

    // DOMImplementation
    virtual bool hasFeature(const std::u16string& feature, const std::u16string& version);
    virtual DocumentType createDocumentType(const std::u16string& qualifiedName, const std::u16string& publicId, const std::u16string& systemId);
    virtual Document createDocument(const std::u16string& _namespace, const std::u16string& qualifiedName, DocumentType doctype);
    virtual Document createHTMLDocument(const std::u16string& title);
    // DOMImplementationCSS
    virtual css::CSSStyleSheet createCSSStyleSheet(const std::u16string& title, const std::u16string& media) throw(DOMException);
    // Object
    virtual Any message_(uint32_t selector, const char* id, int argc, Any* argv)
    {
        return DOMImplementation::dispatch(this, selector, id, argc, argv);
    }
    static const char* const getMetaData()
    {
        return DOMImplementation::getMetaData();
    }
};

DOMImplementationImp* getDOMImplementation();

}}}}  // org::w3c::dom::bootstrap

#endif  // DOMIMPLEMENTATION_IMP_H
