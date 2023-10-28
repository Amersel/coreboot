Scope (_SB)
{
  Mutex (ECAX, 0x01)
  Method (EEAC, 2, Serialized)
  {
      Acquire (ECAX, 0xFFFF)
      Name (EABF, Buffer (0x08){})
      CreateDWordField (EABF, Zero, ECST)
      CreateDWordField (EABF, 0x04, ECPA)
      ECST = Arg0
      ECPA = Arg1
      //EABF = GENS (0x07, EABF, SizeOf (EABF))
      Local0 = ECST /* \_SB_.EEAC.ECST */
      Release (ECAX)
      Return (Local0)
  }
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
  Method (ACEV, 2, NotSerialized)
  {
      Notify (AC, 0x80) // Status Change
  }
}
