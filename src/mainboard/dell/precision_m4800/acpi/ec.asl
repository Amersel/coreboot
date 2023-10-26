/* SPDX-License-Identifier: GPL-2.0-only */

Device(EC)
{
	Name (_HID, EISAID("PNP0C09"))
	Name (_UID, 0)
	Name (_GPE, 16)
	Name (ECRS, ResourceTemplate ()
	{
		IO (Decode16,
			0x0000,             // Range Minimum
			0x0000,             // Range Maximum
			0x00,               // Alignment
			0x01,               // Length
			_Y36)
		IO (Decode16,
			0x0000,             // Range Minimum
			0x0000,             // Range Maximum
			0x00,               // Alignment
			0x01,               // Length
			_Y37)
	})
/* FIXME: EC support */
	OperationRegion (ECOR, EmbeddedControl, 0, 0xFF)
	Field (ECOR, ByteAcc, Lock, Preserve)
	{
		EC00,   8, 
		EC01,   8, 
		EC02,   8, 
		EC03,   8, 
		EC04,   8, 
		EC05,   8, 
		EC06,   8, 
		EC07,   8, 
		EC08,   8, 
		EC09,   8, 
		EC10,   8, 
		EC11,   8, 
		EC12,   8, 
		EC13,   8, 
		EC14,   8, 
		EC15,   8, 
		EC16,   8, 
		EC17,   8, 
		EC18,   8, 
		EC19,   8, 
		EC20,   8, 
		EC21,   8, 
		EC22,   8, 
		EC23,   8, 
		EC24,   8, 
		EC25,   8, 
		EC26,   8, 
		EC27,   8, 
		EC28,   8, 
		EC29,   8, 
		EC30,   8, 
		EC31,   8, 
		EC32,   8, 
		EC33,   8, 
		EC34,   8, 
		EC35,   8, 
		EC36,   8, 
		EC37,   8, 
		EC38,   8, 
		EC39,   8, 
		EC40,   8, 
		EC41,   8, 
		EC42,   8, 
		EC43,   8, 
		EC44,   8, 
		EC45,   8, 
		EC46,   8, 
		EC47,   8, 
		EC48,   8, 
		EC49,   8
	}

	Method (ECR1, 1, NotSerialized)
	{
			//If ((ECRD == Zero))
			//{
			//		Local0 = EISC (0x80, Arg0, Zero)
			//		Return (Local0)
			//}

			// Acquire (ECMX, 0xFFFF)
			Local0 = Zero
			If ((Arg0 == Zero))
			{
					Local0 = EC00 /* \_SB_.PCI0.LPCB.ECDV.EC00 */
			}

			If ((Arg0 == One))
			{
					Local0 = EC01 /* \_SB_.PCI0.LPCB.ECDV.EC01 */
			}

			If ((Arg0 == 0x02))
			{
					Local0 = EC02 /* \_SB_.PCI0.LPCB.ECDV.EC02 */
			}

			If ((Arg0 == 0x03))
			{
					Local0 = EC03 /* \_SB_.PCI0.LPCB.ECDV.EC03 */
			}

			If ((Arg0 == 0x04))
			{
					Local0 = EC04 /* \_SB_.PCI0.LPCB.ECDV.EC04 */
			}

			If ((Arg0 == 0x05))
			{
					Local0 = EC05 /* \_SB_.PCI0.LPCB.ECDV.EC05 */
			}

			If ((Arg0 == 0x06))
			{
					Local0 = EC06 /* \_SB_.PCI0.LPCB.ECDV.EC06 */
			}

			If ((Arg0 == 0x07))
			{
					Local0 = EC07 /* \_SB_.PCI0.LPCB.ECDV.EC07 */
			}

			If ((Arg0 == 0x08))
			{
					Local0 = EC08 /* \_SB_.PCI0.LPCB.ECDV.EC08 */
			}

			If ((Arg0 == 0x09))
			{
					Local0 = EC09 /* \_SB_.PCI0.LPCB.ECDV.EC09 */
			}

			If ((Arg0 == 0x0A))
			{
					Local0 = EC10 /* \_SB_.PCI0.LPCB.ECDV.EC10 */
			}

			If ((Arg0 == 0x0B))
			{
					Local0 = EC11 /* \_SB_.PCI0.LPCB.ECDV.EC11 */
			}

			If ((Arg0 == 0x0C))
			{
					Local0 = EC12 /* \_SB_.PCI0.LPCB.ECDV.EC12 */
			}

			If ((Arg0 == 0x0D))
			{
					Local0 = EC13 /* \_SB_.PCI0.LPCB.ECDV.EC13 */
			}

			If ((Arg0 == 0x0E))
			{
					Local0 = EC14 /* \_SB_.PCI0.LPCB.ECDV.EC14 */
			}

			If ((Arg0 == 0x0F))
			{
					Local0 = EC15 /* \_SB_.PCI0.LPCB.ECDV.EC15 */
			}

			If ((Arg0 == 0x10))
			{
					Local0 = EC16 /* \_SB_.PCI0.LPCB.ECDV.EC16 */
			}

			If ((Arg0 == 0x11))
			{
					Local0 = EC17 /* \_SB_.PCI0.LPCB.ECDV.EC17 */
			}

			If ((Arg0 == 0x12))
			{
					Local0 = EC18 /* \_SB_.PCI0.LPCB.ECDV.EC18 */
			}

			If ((Arg0 == 0x13))
			{
					Local0 = EC19 /* \_SB_.PCI0.LPCB.ECDV.EC19 */
			}

			If ((Arg0 == 0x14))
			{
					Local0 = EC20 /* \_SB_.PCI0.LPCB.ECDV.EC20 */
			}

			If ((Arg0 == 0x15))
			{
					Local0 = EC21 /* \_SB_.PCI0.LPCB.ECDV.EC21 */
			}

			If ((Arg0 == 0x16))
			{
					Local0 = EC22 /* \_SB_.PCI0.LPCB.ECDV.EC22 */
			}

			If ((Arg0 == 0x17))
			{
					Local0 = EC23 /* \_SB_.PCI0.LPCB.ECDV.EC23 */
			}

			If ((Arg0 == 0x18))
			{
					Local0 = EC24 /* \_SB_.PCI0.LPCB.ECDV.EC24 */
			}

			If ((Arg0 == 0x19))
			{
					Local0 = EC25 /* \_SB_.PCI0.LPCB.ECDV.EC25 */
			}

			If ((Arg0 == 0x1A))
			{
					Local0 = EC26 /* \_SB_.PCI0.LPCB.ECDV.EC26 */
			}

			If ((Arg0 == 0x1B))
			{
					Local0 = EC27 /* \_SB_.PCI0.LPCB.ECDV.EC27 */
			}

			If ((Arg0 == 0x1C))
			{
					Local0 = EC28 /* \_SB_.PCI0.LPCB.ECDV.EC28 */
			}

			If ((Arg0 == 0x1D))
			{
					Local0 = EC29 /* \_SB_.PCI0.LPCB.ECDV.EC29 */
			}

			If ((Arg0 == 0x1E))
			{
					Local0 = EC30 /* \_SB_.PCI0.LPCB.ECDV.EC30 */
			}

			If ((Arg0 == 0x1F))
			{
					Local0 = EC31 /* \_SB_.PCI0.LPCB.ECDV.EC31 */
			}

			If ((Arg0 == 0x20))
			{
					Local0 = EC32 /* \_SB_.PCI0.LPCB.ECDV.EC32 */
			}

			If ((Arg0 == 0x21))
			{
					Local0 = EC33 /* \_SB_.PCI0.LPCB.ECDV.EC33 */
			}

			If ((Arg0 == 0x22))
			{
					Local0 = EC34 /* \_SB_.PCI0.LPCB.ECDV.EC34 */
			}

			If ((Arg0 == 0x23))
			{
					Local0 = EC35 /* \_SB_.PCI0.LPCB.ECDV.EC35 */
			}

			If ((Arg0 == 0x24))
			{
					Local0 = EC36 /* \_SB_.PCI0.LPCB.ECDV.EC36 */
			}

			If ((Arg0 == 0x25))
			{
					Local0 = EC37 /* \_SB_.PCI0.LPCB.ECDV.EC37 */
			}

			If ((Arg0 == 0x26))
			{
					Local0 = EC38 /* \_SB_.PCI0.LPCB.ECDV.EC38 */
			}

			If ((Arg0 == 0x27))
			{
					Local0 = EC39 /* \_SB_.PCI0.LPCB.ECDV.EC39 */
			}

			If ((Arg0 == 0x28))
			{
					Local0 = EC40 /* \_SB_.PCI0.LPCB.ECDV.EC40 */
			}

			If ((Arg0 == 0x29))
			{
					Local0 = EC41 /* \_SB_.PCI0.LPCB.ECDV.EC41 */
			}

			If ((Arg0 == 0x2A))
			{
					Local0 = EC42 /* \_SB_.PCI0.LPCB.ECDV.EC42 */
			}

			If ((Arg0 == 0x2B))
			{
					Local0 = EC43 /* \_SB_.PCI0.LPCB.ECDV.EC43 */
			}

			If ((Arg0 == 0x2C))
			{
					Local0 = EC44 /* \_SB_.PCI0.LPCB.ECDV.EC44 */
			}

			If ((Arg0 == 0x2D))
			{
					Local0 = EC45 /* \_SB_.PCI0.LPCB.ECDV.EC45 */
			}

			If ((Arg0 == 0x2E))
			{
					Local0 = EC46 /* \_SB_.PCI0.LPCB.ECDV.EC46 */
			}

			If ((Arg0 == 0x2F))
			{
					Local0 = EC47 /* \_SB_.PCI0.LPCB.ECDV.EC47 */
			}

			If ((Arg0 == 0x30))
			{
					Local0 = EC48 /* \_SB_.PCI0.LPCB.ECDV.EC48 */
			}

			If ((Arg0 == 0x31))
			{
					Local0 = EC49 /* \_SB_.PCI0.LPCB.ECDV.EC49 */
			}

			// Release (ECMX)
			Return (Local0)
	}

	Method (ECW1, 2, NotSerialized)
	{
			//If ((ECRD == Zero))
			//{
			//		EISC (0x81, Arg0, Arg1)
			//		Return (Zero)
			//}

			//Acquire (ECMX, 0xFFFF)
			If ((Arg0 == Zero))
			{
					EC00 = Arg1
			}

			If ((Arg0 == One))
			{
					EC01 = Arg1
			}

			If ((Arg0 == 0x02))
			{
					EC02 = Arg1
			}

			If ((Arg0 == 0x03))
			{
					EC03 = Arg1
			}

			If ((Arg0 == 0x04))
			{
					EC04 = Arg1
			}

			If ((Arg0 == 0x05))
			{
					EC05 = Arg1
			}

			If ((Arg0 == 0x06))
			{
					EC06 = Arg1
			}

			If ((Arg0 == 0x07))
			{
					EC07 = Arg1
			}

			If ((Arg0 == 0x08))
			{
					EC08 = Arg1
			}

			If ((Arg0 == 0x09))
			{
					EC09 = Arg1
			}

			If ((Arg0 == 0x0A))
			{
					EC10 = Arg1
			}

			If ((Arg0 == 0x0B))
			{
					EC11 = Arg1
			}

			If ((Arg0 == 0x0C))
			{
					EC12 = Arg1
			}

			If ((Arg0 == 0x10))
			{
					EC16 = Arg1
			}

			If ((Arg0 == 0x11))
			{
					EC17 = Arg1
			}

			//Release (ECMX)
			Return (Zero)
	}

	Method (ECR2, 1, NotSerialized)
	{
			Local0 = ECR1 (Arg0)
			Arg0++
			Local1 = (ECR1 (Arg0) << 0x08)
			Local0 += Local1
			Return (Local0)
	}
}
