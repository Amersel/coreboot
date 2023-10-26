Device (BAT0)
{
    Name (_HID, EisaId ("PNP0C0A") /* Control Method Battery */)  // _HID: Hardware ID
    Name (_UID, 1)  // _UID: Unique ID
    Name (_PCL, Package () {\_SB})  // _PCL: Power Consumer List

    Method (ECRB, 1, NotSerialized)
    {
        Return (\_SB.PCI0.LPCB.EC.ECR1 (Arg0))
    }

    Method (ECG2, 0, NotSerialized)
    {
        Return (ECBT (Zero, One))
    }

    Method (ECG5, 0, NotSerialized)
    {
        Local0 = ECRB (0x06)
        Return (Local0)
    }

    Method (ECRW, 1, NotSerialized)
    {
        Return (\_SB.PCI0.LPCB.EC.ECR2 (Arg0))
    }

    Method (ECWB, 2, NotSerialized)
    {
        \_SB.PCI0.LPCB.EC.ECW1 (Arg0, Arg1)
    }

    Method (ECBT, 2, NotSerialized)
    {
        Local0 = \_SB.PCI0.LPCB.EC.ECR1 (Arg0)
        Local0 &= Arg1
        If (Local0)
        {
            Return (One)
        }

        Return (Zero)
    }

    Method (ECG6, 2, NotSerialized)
    {
        //Acquire (ECM1, 0xFFFF)
        Local2 = ECG2 ()
        ECWB (0x03, Arg0)
        Arg1 [Zero] = ECRB (0x10)
        Local0 = ECRW (0x12)
        If ((Local0 == Zero))
        {
            Local0++
        }
        ElseIf ((Local2 != Zero))
        {
            If ((Local0 & 0x8000))
            {
                Local0 = Ones
            }
        }
        ElseIf ((Local0 & 0x8000))
        {
            Local0 = (Zero - Local0)
            Local0 &= 0xFFFF
        }
        Else
        {
            Local0 = Ones
        }

        Arg1 [One] = Local0
        Local0 = ECRW (0x16)
        Arg1 [0x02] = Local0
        Local0 = ECRW (0x14)
        Arg1 [0x03] = Local0
        //Release (ECM1)
    }

    Method (_STA, 0, NotSerialized)  // _STA: Status
    {
        Local0 = ECG5 ()
        Local0 &= 0x02
        If (Local0)
        {
            Return (0x1F)
        }

        Return (0x0F)
    }

    //Method (_BIF, 0, Serialized)  // _BIF: Battery Information
    //{
    //    Name (BIF0, Package (0x0D){})
    //    ECG9 (One, BIF0)
    //    Return (BIF0) /* \_SB_.BAT0._BIF.BIF0 */
    //}

    Method (_BST, 0, Serialized)  // _BST: Battery Status
    {
        Name (BST0, Package (0x04){})
        ECG6 (One, BST0)
        Return (BST0) /* \_SB_.BAT0._BST.BST0 */
    }
}