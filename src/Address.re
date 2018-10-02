
let component = ReasonReact.statelessComponent("Address");

let make = (_children) => {
  ...component,
  render: (_self) =>
  <table id="address">

  <tr>
          <td className=Styles.label>( ReasonReact.string("Street address") )</td>
          <td className=Styles.slimField>
          <input className=Styles.field id="street_number" >
          </input>
          </td>
          <td className=Styles.wideField colSpan=2>
          <input className=Styles.field id="route" >
          </input>
          </td>
  </tr>

  <tr>
         <td className=Styles.label>( ReasonReact.string("City") )</td>
          <td className=Styles.wideField colSpan=3>
          <input className=Styles.field id="locality" >
          </input>
          </td>

        </tr>
        <tr>
          <td className=Styles.label>( ReasonReact.string("State") )</td>
          <td className=Styles.slimField>
          <input className=Styles.field id="administrative_area_level_1" >
          </input>
          </td>

          <td className=Styles.label>( ReasonReact.string("Zip code") )</td>
          <td className=Styles.wideField>
          <input className=Styles.field id="postal_code" >
          </input>
          </td>
        </tr>

        <tr>
          <td className=Styles.label>( ReasonReact.string("Country") )</td>
          <td className=Styles.wideField colSpan=3>
          <input className=Styles.field id="country">
          </input>
          </td>
        </tr>

  </table>
};