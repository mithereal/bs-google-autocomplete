open Googleplaces

let componentForm = () => {
street_number: "short_name",
route: "long_name",
locality: "long_name",
administrative_area_level_1: "short_name",
country: "long_name",
postal_code: "short_name"
};

let fillInAddress = () => {
Js.log("fillinaddress");
};

let geolocate = () => {};

let component = ReasonReact.statelessComponent("Input");

let initAutocomplete = (id) => {

 let el = autocomplete(getElementById(doc, id), types );

 addListener(getElementById(doc, id), "place_changed", fillInAddress())

 Js.log(id);
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