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

Event::Event(const Rocket::Core::String& value, Rocket::Core::Context* context) : value(value), Context(context)
{
}

Event::~Event()
{
}

void Event::ProcessEvent(Rocket::Core::Event& event)
{
    if(event.GetTargetElement()->GetId() == "dropdown-button") {
        printf("dropdown");
        Rocket::Core::Element* element = Context->GetDocument(0)->GetElementById("dropdown-content");
        if(element->GetProperty("display")->ToString() == "block") {
            element->SetProperty("display", "none");
        }
        else {
            element->SetProperty("display", "block");
        }
    }
    else {

        printf("button click\n");
        Context->UnloadAllDocuments();
        //Rocket::Core::ElementDocument* document = Context->LoadDocument("media/assets/second.rml");
        Rocket::Core::ElementDocument* document = Context->LoadDocument("media/assets/" + value + ".rml");
        if (document != NULL)
        {
            document->Focus();
            document->Show();
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
