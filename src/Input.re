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

 let marshall = (components, len) => {
 Js.log(components)
  let el = switch (len) {
          | 1 =>  {
                   "street_number": "",
                   "route":"",
                   "locality": "",
                   "administrative_area_level_1": "",
                   "country": components[0]##long_name,
                   "postal_code": "",
                   }
          | 2 =>  {
                    "street_number": "",
                    "route":"",
                    "locality": "",
                    "administrative_area_level_1": components[0]##short_name,
                    "country": components[1]##long_name,
                    "postal_code": "",
          }
          | 4 =>  {
                    "street_number": "",
                    "route":"",
                    "locality": components[0]##long_name,
                    "administrative_area_level_1": components[2]##short_name,
                    "country": components[3]##long_name,
                    "postal_code": "",
          }
          | 5 =>  {
                    "street_number": "",
                    "route":components[0]##long_name,
                    "locality": "",
                    "administrative_area_level_1": components[2]##short_name,
                    "country": components[3]##long_name,
                    "postal_code": components[4]##short_name,
          }
          | 6 =>  {
                    "street_number": "",
                    "route":"",
                    "locality": components[1]##long_name,
                    "administrative_area_level_1": components[3]##short_name,
                    "country": components[4]##long_name,
                    "postal_code": components[5]##short_name
          }
          | 7 =>  {
                   "street_number": components[0]##long_name,
                   "route": components[1]##long_name,
                   "locality": components[2]##long_name,
                   "administrative_area_level_1": components[4]##short_name,
                   "country": components[5]##long_name,
                   "postal_code": components[6]##short_name
                   }
          | 8 =>  {
                    "street_number": components[0]##long_name,
                    "route": components[1]##long_name,
                    "locality": components[4]##long_name,
                    "administrative_area_level_1": components[5]##short_name,
                    "country": components[6]##long_name,
                    "postal_code": components[7]##short_name
                    }
                    | 9 =>  {
                    "street_number": components[0]##long_name,
                    "route": components[1]##long_name,
                    "locality": components[3]##long_name,
                    "administrative_area_level_1": components[5]##short_name,
                    "country": components[6]##long_name,
                    "postal_code": components[7]##short_name ++ "-" ++ components[8]##short_name
                    }
        };

    el
 }

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

let geolocate = () => {};

let component = ReasonReact.statelessComponent("Input");

let initAutocomplete = (id) => {

 let el = autocomplete(Document.getElementById(id, document), types );

  addListener(el, "place_changed", () => fillInAddress(el));

()
};

let make = (~placeholder, ~id, _children) => {
  ...component,
  didMount: self => {
       initAutocomplete(id);
      },
  render: (_self) =>
  <div id = "input">
  <input id= id placeholder= placeholder type_="text" />

  </div>
};