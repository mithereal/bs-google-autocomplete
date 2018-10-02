open Googleplaces
open Webapi.Dom

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

 for (idx in 0 to component_array_length) {
    let el = Document.getElementById(component_array[idx], document);

 };

Js.log(component_length);
};

let geolocate = () => {};

let component = ReasonReact.statelessComponent("Input");

let initAutocomplete = (id) => {

 let el = autocomplete(Document.getElementById(id, document), types );

  addListener(el, "place_changed", () => fillInAddress(el));

 Js.log(el);
};

let make = (~placeholder, ~id, _children) => {
  ...component,
  didMount: self => {
       initAutocomplete(id);
      },
  render: (_self) =>
  <div>
  <input id= id placeholder= placeholder type_="text" />
  <Address />

  </div>
};