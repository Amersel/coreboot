Device (AC)
{
    Name (_HID, "ACPI0003" /* Power Source Device */)  // _HID: Hardware ID
    Method (_PCL, 0, NotSerialized)  // _PCL: Power Consumer List
    {
        Return (Package (0x04)
        {
            _SB, 
            BAT0, 
            BAT1, 
            BAT2
        })
    }

    Method (_PSR, 0, NotSerialized)  // _PSR: Power Source
    {
        Local0 = ECG5 ()
        Local0 &= One
        If ((Local0 != PWRS))
        {
            PWRS = Local0
            PNOT ()
        }

        Return (Local0)
    }

    Method (_STA, 0, NotSerialized)  // _STA: Status
    {
        Return (0x0F)
    }
}
