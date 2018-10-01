open Googleplaces

let componentForm = () => {
"street_number": "short_name",
"route": "long_name",
"locality": "long_name",
"administrative_area_level_1": "short_name",
"country": "long_name",
"postal_code": "short_name"
};

let fillInAddress = (autocomplete) => {
 let place = getPlace(autocomplete);
 let componentForm = componentForm();
 let components = place##address_components;
 let component_length = Array.length(components);

Js.log(component_length);
};

let geolocate = () => {};

let component = ReasonReact.statelessComponent("Input");

let initAutocomplete = (id) => {

 let el = autocomplete(getElementById(doc, id), types );
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
  </div>
};