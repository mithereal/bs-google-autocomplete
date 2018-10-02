type componentForm = {.
"street_number": string,
"route": string,
"locality": string,
"administrative_area_level_1": string,
"country": string,
"postal_code": string
};

type address_components = {.
"street_number" : string,
"route" : string,
"locality" : string,
"administrative_area_level_1" : string,
"country" : string,
"postal_code": string
};

type component = {.
"long_name" : string,
"short_name" : string,
"types" : array(string)
};

type autocomplete = {.
[@bs.meth] "addListener" : (string, unit) => unit,
[@bs.meth] "getPlace" : unit => unit,
"address_components" : array(component),
};


type geolocation = {.
  "lat": string,
  "lng": string,
};

type circle = {.
  "center": geolocation,
  "radius": string,
};

[@bs.deriving abstract]
type setup = {
  types: array(string),
};

[@bs.new] external autocomplete : (option(Dom.element), setup) => autocomplete = "google.maps.places.Autocomplete";

[@bs.new] external circle : (circle) => autocomplete = "google.maps.places.Circle";

[@bs.send] external addListener : (autocomplete, string, unit => unit) => autocomplete = "addListener";

[@bs.send] external getPlace : (autocomplete) => autocomplete = "getPlace";

let types = setup(~types=[|"geocode"|]);

let marshall = (components, len) => {

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