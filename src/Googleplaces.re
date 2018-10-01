type domElement = {.
"value": string
};

type document = {.
[@bs.meth] "getElementById" : string => domElement
};

type componentForm = {.
"street_number": string,
"route": string,
"locality": string,
"administrative_area_level_1": string,
"country": string,
"postal_code": string
};


type autocomplete = {.
[@bs.meth] "addListener" : (string, unit) => unit,
[@bs.meth] "getPlace" : unit => unit,
"address_components" : array(string)
};

type response = {.

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

[@bs.val] external doc : document = "document";

[@bs.send] external getElementById : (document, string) => domElement = "getElementById";

[@bs.send] external preventEventDefault : (ReactEventRe.Form.t) => unit = "preventDefault";

[@bs.new] external autocomplete : (domElement, setup) => autocomplete = "google.maps.places.Autocomplete";

[@bs.new] external circle : (circle) => autocomplete = "google.maps.places.Circle";

[@bs.send] external addListener : (autocomplete, string, unit => unit) => autocomplete = "addListener";

[@bs.send] external getPlace : (autocomplete) => autocomplete = "getPlace";

let types = setup(~types=[|"geocode"|]);