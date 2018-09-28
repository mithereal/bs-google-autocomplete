let component = ReasonReact.statelessComponent("Places");

let make = (_children) => {
...component,
render: (_self) =>
                     <div>

                     <Input
                      id="start_autocomplete"
                      placeholder="start address"
                      />

                     <Input
                       id="end_autocomplete"
                       placeholder="end address"
                       />

                       <div id="add_element">
                       <button> ( ReasonReact.string("+") ) </button>
                       </div>

                       <div id="submit">
                       <button> ( ReasonReact.string("Submit") ) </button>
                       </div>

                      </div>
};
