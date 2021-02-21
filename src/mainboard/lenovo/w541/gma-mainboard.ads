-- SPDX-License-Identifier: GPL-2.0-or-later

with HW.GFX.GMA;
with HW.GFX.GMA.Display_Probing;

use HW.GFX.GMA;
use HW.GFX.GMA.Display_Probing;

private package GMA.Mainboard is

   -- FIXME: check this
   ports : constant Port_List :=
     (DP1,
      DP2,
      Analog,
      eDP,
      others => Disabled);

end GMA.Mainboard;
