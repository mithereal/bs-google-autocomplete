type domElement = {.
"value": string
};

type document = {.
[@bs.meth] "getElementById" : string => domElement
};

type componentForm = {
street_number: string,
route: string,
locality: string,
administrative_area_level_1: string,
country: string,
postal_code: string
};

type autocomplete =
| ADDLISTENER(string, unit)
| GETPLACE

type response = {.
};

[@bs.deriving abstract]
type geolocation = {
  lat: string,
  lng: string,
};

[@bs.deriving abstract]
type circle = {
  center: geolocation,
  radius: string,
};

[@bs.deriving abstract]
type setup = {
  types: list(string),
};

[@bs.val] external doc : document = "document";

[@bs.send] external getElementById : (document, string) => domElement = "getElementById";

[@bs.send] external preventEventDefault : (ReactEventRe.Form.t) => unit = "preventDefault";

[@bs.new] external autocomplete : (domElement, setup) => autocomplete = "google.maps.places.Autocomplete";

[@bs.new] external circle : (circle) => response = "google.maps.places.Circle";

[@bs.new] external addListener : (domElement, string, unit) => unit = "google.maps.event.addListener";

let types = setup(~types=["geocode"]);