# Reasonml Google Places Api Binding

#### Example reasonml google places api binding

###### Docs: https://developers.google.com/maps/documentation/javascript/examples/places-autocomplete-addressform

###### Example:
view the example folder for an example react app, the main logic happens in input.re.

ex.

open Googleplaces

open Webapi.Dom

type state =
 | INIT
 | LOADED

type action =
| GEOLOCATE

let componentForm = () => {
"street_number": "short_name",
"route": "long_name",
"locality": "long_name",
"administrative_area_level_1": "short_name",
"country": "long_name",
"postal_code": "short_name"
};

let component_array = [|"street_number","route","locality","administrative_area_level_1","country","postal_code"|]

let fillInAddress = (autocomplete) => {
 let place = getPlace(autocomplete);
 let componentForm = componentForm();
 let components = place##address_components;
 let component_array_length = Array.length(component_array);
 let component_length = Array.length(components);

let marshalled = marshall(components, component_length)

 for (idx in 0 to component_array_length -1) {
    let el = Document.getElementById(component_array[idx], document);
    let () = switch (el) {
         | Some(element) => Element.setAttribute("value", "", element);
           Element.setAttribute("disabled", "false", element)
         | None => ()
       };
};
 for (idx in 0 to component_array_length -1) {
     let el = Document.getElementById(component_array[idx], document);
     let () = switch (el) {
              | Some(element) =>
              switch (component_array[idx]) {
              | "street_number" => Element.setAttribute("value", marshalled##street_number, element)
              | "route" => Element.setAttribute("value", marshalled##route, element)
              | "locality" => Element.setAttribute("value", marshalled##locality, element)
              | "administrative_area_level_1" => Element.setAttribute("value", marshalled##administrative_area_level_1, element)
              | "country" => Element.setAttribute("value", marshalled##country, element)
              | "postal_code" => Element.setAttribute("value", marshalled##postal_code, element)
               | _ => ()
              }
             | None => ()
            };
            };
};

let geolocate = () => {
let navigator = Window.navigator(window);
};


let reducer = (action,_self) =>
 switch(action) {
 | GEOLOCATE => geolocate();
                ReasonReact.Update(LOADED)

}


let initAutocomplete = (id) => {

 let el = autocomplete(Document.getElementById(id, document), types );

  addListener(el, "place_changed", () => fillInAddress(el));

()
};

let component = ReasonReact.reducerComponent("Input");

let make = (~placeholder, ~id, _children) => {
  ...component,
    initialState: () => INIT,
    reducer,
  didMount: self => {
       initAutocomplete(id);
      },
  render: (self) =>
  <div id = "input"> l
  <input id= id placeholder= placeholder type_="text" onFocus=(_event => self.send(GEOLOCATE)) />

  </div>
};