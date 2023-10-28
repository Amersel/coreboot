Device (BAT0)
{
    Name (_HID, EisaId ("PNP0C0A") /* Control Method Battery */)  // _HID: Hardware ID
    Name (_UID, 1)  // _UID: Unique ID
    Name (_PCL, Package () {\_SB})  // _PCL: Power Consumer List
    Mutex (ECM1, 0x01)
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
        Acquire (ECM1, 0xFFFF)
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
        Release (ECM1)
    }

    Method (ECM8, 1, NotSerialized)
    {
        ECWB (0x04, Arg0)
        Name (LBUF, Buffer (0x21){})
        Local0 = Zero
        While ((Local0 < 0x20))
        {
            Local1 = ECRB (0x2A)
            LBUF [Local0] = Local1
            If ((Local1 == Zero))
            {
                Break
            }

            Local0++
        }

        If ((Local1 != Zero))
        {
            LBUF [Local0] = Zero
            Local0++
        }

        Local0++
        Name (OBUF, Buffer (Local0){})
        OBUF = LBUF /* \ECM8.LBUF */
        Return (OBUF) /* \ECM8.OBUF */
    }

    Name (BS01, Package (0x03)
    {
        One, 
        0xFF, 
        "Unknown"
    })
    Name (BS02, Package (0x0F)
    {
        0x03, 
        0x02, 
        "Sony", 
        0x03, 
        "Sanyo", 
        0x04, 
        "Panasonic", 
        0x07, 
        "SMP", 
        0x08, 
        "Motorola", 
        0x06, 
        "Samsung SDI", 
        0xFF, 
        "Unknown"
    })
    Name (BS03, Package (0x13)
    {
        0x02, 
        One, 
        "PbAc", 
        0x02, 
        "LION", 
        0x03, 
        "NiCd", 
        0x04, 
        "NiMH", 
        0x05, 
        "NiZn", 
        0x06, 
        "RAM", 
        0x07, 
        "ZnAR", 
        0x08, 
        "LiP", 
        0xFF, 
        "Unknown"
    })
    Method (XPTB, 1, NotSerialized)
    {
        Local0 = SizeOf (Arg0)
        If ((ObjectType (Arg0) == 0x02))
        {
            Local0++
        }

        Name (OBUF, Buffer (Local0){})
        OBUF = Arg0
        If ((ObjectType (Arg0) == 0x02))
        {
            Local0--
            OBUF [Local0] = Zero
        }

        Return (OBUF) /* \XPTB.OBUF */
    }
    Method (STDG, 3, NotSerialized)
    {
        Local0 = Arg0
        If ((Arg0 >= 0x0A))
        {
            Divide (Arg0, 0x0A, Local0, Local1)
            Arg2 = STDG (Local1, Arg1, Arg2)
        }

        Local0 += 0x30
        Arg1 [Arg2] = Local0
        Arg2++
        Return (Arg2)
    }
    Method (XPTS, 1, NotSerialized)
    {
        Name (LBUF, Buffer (0x20){})
        Local0 = STDG (Arg0, LBUF, Zero)
        LBUF [Local0] = Zero
        Local0++
        Name (OBUF, Buffer (Local0){})
        OBUF = LBUF /* \XPTS.LBUF */
        Return (OBUF) /* \XPTS.OBUF */
    }
    Method (ECU0, 2, NotSerialized)
    {
        Local0 = One
        Local1 = Zero
        While ((Local1 != 0xFF))
        {
            Local1 = DerefOf (Arg0 [Local0])
            If ((Arg1 == Local1))
            {
                Local0++
                Local2 = DerefOf (Arg0 [Local0])
                Local2 = XPTB (Local2)
                Return (Local2)
            }

            Local0 += 0x02
        }

        Local2 = DerefOf (Arg0 [Zero])
        Local2 = ECM8 (Local2)
        Return (Local2)
    }
    Method (ECG9, 2, NotSerialized)
    {
        Acquire (ECM1, 0xFFFF)
        ECWB (0x03, Arg0)
        Arg1 [Zero] = One
        Local0 = ECRW (0x20)
        Arg1 [One] = Local0
        Local1 = ECRW (0x1E)
        Arg1 [0x02] = Local1
        Arg1 [0x03] = One
        Local2 = ECRW (0x22)
        Arg1 [0x04] = Local2
        Local3 = Local0 / 0x0A
        Arg1 [0x05] = Local3
        Local3 = Local0 / 0x21
        Arg1 [0x06] = Local3
        Local3 = Local0 / 0x64
        Arg1 [0x07] = Local3
        Arg1 [0x08] = Local3
        Local3 = ECU0 (BS01, Zero)
        Arg1 [0x09] = Local3
        Local3 = ECRW (0x26)
        Local3 = XPTS (Local3)
        Arg1 [0x0A] = Local3
        Local3 = ECRB (0x29)
        Local3 = ECU0 (BS03, Local3)
        Arg1 [0x0B] = Local3
        Local3 = ECRB (0x28)
        Local3 = ECU0 (BS02, Local3)
        Arg1 [0x0C] = Local3
        Release (ECM1)
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

    Method (_BIF, 0, Serialized)  // _BIF: Battery Information
    {
        Name (BIF0, Package (0x0D){})
        ECG9 (One, BIF0)
        Return (BIF0) /* \_SB_.BAT0._BIF.BIF0 */
    }

    Method (_BST, 0, Serialized)  // _BST: Battery Status
    {
        Name (BST0, Package (0x04){})
        ECG6 (One, BST0)
        Return (BST0) /* \_SB_.BAT0._BST.BST0 */
    }
}