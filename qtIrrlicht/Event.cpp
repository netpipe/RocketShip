/*
 * This source file is part of libRocket, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://www.librocket.com
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include "Event.h"
#include <Rocket/Core.h>
#include <Rocket/Controls.h>
#include <iostream>

Event::Event(const Rocket::Core::String& value, Rocket::Core::Context* context) : value(value), Context(context)
{
}

Event::~Event()
{
}

void Event::ProcessEvent(Rocket::Core::Event& event)
{
    int numDocuments = Context->GetNumDocuments();
    if(event.GetTargetElement()->GetId() == "close") {
        printf("close");
        event.GetTargetElement()->GetOwnerDocument()->Close();
    }
    else if(event.GetTargetElement()->GetId() == "dropdown-button") {
        printf("dropdown");
        //Rocket::Core::Element* element = Context->GetDocument(numDocuments-1)->GetElementById("dropdown-content");
        Rocket::Core::Element* element = event.GetTargetElement()->GetOwnerDocument()->GetElementById("dropdown-content");
        if(element != NULL) {
            if(element->GetProperty("display")->ToString() == "block") {
                element->SetProperty("display", "none");
            }
            else {
                element->SetProperty("display", "block");
            }
        }
    }
    else if(event.GetTargetElement()->GetId() == "dropdown-button-2") {
        printf("dropdown");
        //Rocket::Core::Element* element = Context->GetDocument(numDocuments-1)->GetElementById("dropdown-content-2");
        Rocket::Core::Element* element = event.GetTargetElement()->GetOwnerDocument()->GetElementById("dropdown-content-2");
        if(element != NULL) {
            if(element->GetProperty("display")->ToString() == "block") {
                element->SetProperty("display", "none");
            }
            else {
                element->SetProperty("display", "block");
            }
        }
    }
    else if(event.GetTargetElement()->GetId() == "sites") {
        printf("sub-dropdown");
        Rocket::Core::Element* element = Context->GetDocument(numDocuments-1)->GetElementById("sub-dropdown");
        if(element != NULL) {
            if(element->GetProperty("display")->ToString() == "block") {
                element->SetProperty("display", "none");
            }
            else {
                element->SetProperty("display", "block");
            }
        }
    }
    else if(event.GetTargetElement()->GetId() == "form"){
        printf("form\n");
        Rocket::Core::Element* textElement = event.GetTargetElement()->GetOwnerDocument()->GetElementById("textarea");
        Rocket::Controls::ElementFormControlTextArea* text_area = dynamic_cast< Rocket::Controls::ElementFormControlTextArea* >(textElement);
        std::cout<<"value: "<<text_area->GetValue().CString()<<std::endl;
    }
    else if(event.GetTargetElement()->GetId() == "open-button"){
        printf("open-button\n");
        Rocket::Core::ElementDocument* document = Context->LoadDocument("media/assets/" + value + ".rml");
        if (document != NULL)
        {
            document->Show();
            document->Focus();
            document->RemoveReference();
        }
    }
    else {
        printf("button click\n");
        //Rocket::Core::ElementDocument* currentDocument = Context->GetDocument(numDocuments-1);
        //Context->UnloadDocument(currentDocument);
        //Rocket::Core::ElementDocument* document = Context->LoadDocument("media/assets/second.rml");
        event.GetTargetElement()->GetOwnerDocument()->Close();
        Rocket::Core::ElementDocument* document = Context->LoadDocument("media/assets/" + value + ".rml");
        if (document != NULL)
        {
            document->Show();
            document->Focus();
            document->RemoveReference();
        }
    }
}

// Destroys the event.
void Event::OnDetach(Rocket::Core::Element* ROCKET_UNUSED_PARAMETER(element))
{
	ROCKET_UNUSED(element);

	delete this;
}
