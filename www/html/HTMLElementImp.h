/*
 * Copyright 2010, 2011 Esrille Inc.
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

#ifndef HTMLELEMENT_IMP_H
#define HTMLELEMENT_IMP_H

#include <Object.h>
#include <org/w3c/dom/html/HTMLElement.h>

#include <org/w3c/dom/css/CSSStyleDeclaration.h>
#include <org/w3c/dom/Element.h>
#include <org/w3c/dom/NodeList.h>
#include <org/w3c/dom/DOMTokenList.h>
#include <org/w3c/dom/DOMSettableTokenList.h>
#include <org/w3c/dom/DOMStringMap.h>
#include <org/w3c/dom/html/HTMLMenuElement.h>
#include <org/w3c/dom/html/Function.h>
#include <org/w3c/dom/html/HTMLPropertiesCollection.h>

#include "ElementImp.h"

namespace org { namespace w3c { namespace dom { namespace bootstrap {

class HTMLElementImp : public ObjectMixin<HTMLElementImp, ElementImp>
{
    css::CSSStyleDeclaration style;

public:
    HTMLElementImp(DocumentImp* ownerDocument, const std::u16string& localName);
    HTMLElementImp(HTMLElementImp* org, bool deep);
    ~HTMLElementImp();

    virtual void eval();

    // Node
    virtual Node cloneNode(bool deep);
    // HTMLElement
    NodeList getElementsByClassName(std::u16string classNames);
    virtual std::u16string getInnerHTML();
    virtual void setInnerHTML(std::u16string innerHTML);
    virtual std::u16string getOuterHTML();
    virtual void setOuterHTML(std::u16string outerHTML);
    virtual void insertAdjacentHTML(std::u16string position, std::u16string text);
    virtual std::u16string getId();
    virtual void setId(std::u16string id);
    virtual std::u16string getTitle();
    virtual void setTitle(std::u16string title);
    virtual std::u16string getLang();
    virtual void setLang(std::u16string lang);
    virtual std::u16string getDir();
    virtual void setDir(std::u16string dir);
    virtual std::u16string getClassName();
    virtual void setClassName(std::u16string className);
    virtual DOMTokenList getClassList();
    virtual DOMStringMap getDataset();
    virtual bool getHidden();
    virtual void setHidden(bool hidden);
    virtual void click();
    virtual void scrollIntoView();
    virtual void scrollIntoView(bool top);
    virtual int getTabIndex();
    virtual void setTabIndex(int tabIndex);
    virtual void focus();
    virtual void blur();
    virtual std::u16string getAccessKey();
    virtual void setAccessKey(std::u16string accessKey);
    virtual std::u16string getAccessKeyLabel();
    virtual bool getDraggable();
    virtual void setDraggable(bool draggable);
    virtual std::u16string getContentEditable();
    virtual void setContentEditable(std::u16string contentEditable);
    virtual bool getIsContentEditable();
    virtual html::HTMLMenuElement getContextMenu();
    virtual void setContextMenu(html::HTMLMenuElement contextMenu);
    virtual std::u16string getSpellcheck();
    virtual void setSpellcheck(std::u16string spellcheck);
    virtual std::u16string getCommandType();
    virtual std::u16string getLabel();
    virtual std::u16string getIcon();
    virtual bool getDisabled();
    virtual bool getChecked();
    virtual css::CSSStyleDeclaration getStyle();
    virtual html::Function getOnabort();
    virtual void setOnabort(html::Function onabort);
    virtual html::Function getOnblur();
    virtual void setOnblur(html::Function onblur);
    virtual html::Function getOncanplay();
    virtual void setOncanplay(html::Function oncanplay);
    virtual html::Function getOncanplaythrough();
    virtual void setOncanplaythrough(html::Function oncanplaythrough);
    virtual html::Function getOnchange();
    virtual void setOnchange(html::Function onchange);
    virtual html::Function getOnclick();
    virtual void setOnclick(html::Function onclick);
    virtual html::Function getOncontextmenu();
    virtual void setOncontextmenu(html::Function oncontextmenu);
    virtual html::Function getOndblclick();
    virtual void setOndblclick(html::Function ondblclick);
    virtual html::Function getOndrag();
    virtual void setOndrag(html::Function ondrag);
    virtual html::Function getOndragend();
    virtual void setOndragend(html::Function ondragend);
    virtual html::Function getOndragenter();
    virtual void setOndragenter(html::Function ondragenter);
    virtual html::Function getOndragleave();
    virtual void setOndragleave(html::Function ondragleave);
    virtual html::Function getOndragover();
    virtual void setOndragover(html::Function ondragover);
    virtual html::Function getOndragstart();
    virtual void setOndragstart(html::Function ondragstart);
    virtual html::Function getOndrop();
    virtual void setOndrop(html::Function ondrop);
    virtual html::Function getOndurationchange();
    virtual void setOndurationchange(html::Function ondurationchange);
    virtual html::Function getOnemptied();
    virtual void setOnemptied(html::Function onemptied);
    virtual html::Function getOnended();
    virtual void setOnended(html::Function onended);
    virtual html::Function getOnerror();
    virtual void setOnerror(html::Function onerror);
    virtual html::Function getOnfocus();
    virtual void setOnfocus(html::Function onfocus);
    virtual html::Function getOnformchange();
    virtual void setOnformchange(html::Function onformchange);
    virtual html::Function getOnforminput();
    virtual void setOnforminput(html::Function onforminput);
    virtual html::Function getOninput();
    virtual void setOninput(html::Function oninput);
    virtual html::Function getOninvalid();
    virtual void setOninvalid(html::Function oninvalid);
    virtual html::Function getOnkeydown();
    virtual void setOnkeydown(html::Function onkeydown);
    virtual html::Function getOnkeypress();
    virtual void setOnkeypress(html::Function onkeypress);
    virtual html::Function getOnkeyup();
    virtual void setOnkeyup(html::Function onkeyup);
    virtual html::Function getOnload();
    virtual void setOnload(html::Function onload);
    virtual html::Function getOnloadeddata();
    virtual void setOnloadeddata(html::Function onloadeddata);
    virtual html::Function getOnloadedmetadata();
    virtual void setOnloadedmetadata(html::Function onloadedmetadata);
    virtual html::Function getOnloadstart();
    virtual void setOnloadstart(html::Function onloadstart);
    virtual html::Function getOnmousedown();
    virtual void setOnmousedown(html::Function onmousedown);
    virtual html::Function getOnmousemove();
    virtual void setOnmousemove(html::Function onmousemove);
    virtual html::Function getOnmouseout();
    virtual void setOnmouseout(html::Function onmouseout);
    virtual html::Function getOnmouseover();
    virtual void setOnmouseover(html::Function onmouseover);
    virtual html::Function getOnmouseup();
    virtual void setOnmouseup(html::Function onmouseup);
    virtual html::Function getOnmousewheel();
    virtual void setOnmousewheel(html::Function onmousewheel);
    virtual html::Function getOnpause();
    virtual void setOnpause(html::Function onpause);
    virtual html::Function getOnplay();
    virtual void setOnplay(html::Function onplay);
    virtual html::Function getOnplaying();
    virtual void setOnplaying(html::Function onplaying);
    virtual html::Function getOnprogress();
    virtual void setOnprogress(html::Function onprogress);
    virtual html::Function getOnratechange();
    virtual void setOnratechange(html::Function onratechange);
    virtual html::Function getOnreadystatechange();
    virtual void setOnreadystatechange(html::Function onreadystatechange);
    virtual html::Function getOnscroll();
    virtual void setOnscroll(html::Function onscroll);
    virtual html::Function getOnseeked();
    virtual void setOnseeked(html::Function onseeked);
    virtual html::Function getOnseeking();
    virtual void setOnseeking(html::Function onseeking);
    virtual html::Function getOnselect();
    virtual void setOnselect(html::Function onselect);
    virtual html::Function getOnshow();
    virtual void setOnshow(html::Function onshow);
    virtual html::Function getOnstalled();
    virtual void setOnstalled(html::Function onstalled);
    virtual html::Function getOnsubmit();
    virtual void setOnsubmit(html::Function onsubmit);
    virtual html::Function getOnsuspend();
    virtual void setOnsuspend(html::Function onsuspend);
    virtual html::Function getOntimeupdate();
    virtual void setOntimeupdate(html::Function ontimeupdate);
    virtual html::Function getOnvolumechange();
    virtual void setOnvolumechange(html::Function onvolumechange);
    virtual html::Function getOnwaiting();
    virtual void setOnwaiting(html::Function onwaiting);
    // HTMLElement-3
    virtual Element getOffsetParent();
    virtual int getOffsetTop();
    virtual int getOffsetLeft();
    virtual int getOffsetWidth();
    virtual int getOffsetHeight();
    // HTMLElement-37
    virtual bool getItemScope();
    virtual void setItemScope(bool itemScope);
    virtual std::u16string getItemType();
    virtual void setItemType(std::u16string itemType);
    virtual std::u16string getItemId();
    virtual void setItemId(std::u16string itemId);
    virtual DOMSettableTokenList getItemRef();
    virtual void setItemRef(std::u16string itemRef);
    virtual DOMSettableTokenList getItemProp();
    virtual void setItemProp(std::u16string itemProp);
    virtual html::HTMLPropertiesCollection getProperties();
    virtual Any getItemValue();
    virtual void setItemValue(Any itemValue);

    // Object
    virtual Any message_(uint32_t selector, const char* id, int argc, Any* argv) {
        return html::HTMLElement::dispatch(this, selector, id, argc, argv);
    }
    static const char* const getMetaData()
    {
        return html::HTMLElement::getMetaData();
    }
};

}}}}  // org::w3c::dom::bootstrap

#endif  // HTMLELEMENT_IMP_H