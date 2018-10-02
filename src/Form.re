let component = ReasonReact.statelessComponent("Places");

let make = (_children) => {
...component,
render: (_self) =>
                     <div>

                     <Input
                      id="start_autocomplete"
                      placeholder="start address"
                      />

                      <Address />

                      </div>
};
