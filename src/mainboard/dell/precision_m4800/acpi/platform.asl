/* SPDX-License-Identifier: GPL-2.0-only */
Name (TRTD, 0x02)
Name (TRTI, 0x03)
Name (PFTI, 0x04)
Method(_WAK, 1)
{
	/* FIXME: EC support  */
	P8XH (One, 0xAB)
	Return(Package() {0, 0})
}

Method(_PTS,1)
{
	/* FIXME: EC support  */
	P80D = Zero
	P8XH (Zero, Arg0)

	If ((Arg0 == 0x03))
	{
			If ((PWRS == Zero))
			{
					//\_SB.PCI0.XHC.PMEB = Zero
					//\_SB.PCI0.EHC1.PMEB = Zero
					//\_SB.PCI0.EHC2.PMEB = Zero
					//If ((\_SB.PCI0.XHC.PMST == One))
					//{
					//		\_SB.PCI0.XHC.PMST = One
					//}

					//If ((\_SB.PCI0.EHC1.PMST == One))
					//{
					//		\_SB.PCI0.EHC1.PMST = One
					//}

					//If ((\_SB.PCI0.EHC2.PMST == One))
					//{
					//		\_SB.PCI0.EHC2.PMST = One
					//}
			}
			ElseIf (((OSYS == 0x07D2) || (OSYS == 0x07D1)))
			{
					//USBL = One
					//CAMD = PO12 /* \PO12 */
					//PO12 = One
					//USBL = Zero
					Sleep (0x14)
					//If ((\_SB.PCI0.EHC2.PMST == One))
					//{
					//		\_SB.PCI0.EHC2.PMST = One
					//}
			}

			If ((DTSE && (TCNT > One)))
			{
					TRAP (TRTD, 0x1E)
			}
	}
}

Method (TRAP, 2, Serialized)
{
		SMIF = Arg1
		If ((Arg0 == TRTD))
		{
				DTSF = Arg1
				TRPD = Zero
				Return (DTSF) /* \DTSF */
		}

		If ((Arg0 == TRTI))
		{
				TRPH = Zero
		}

		If ((Arg0 == PFTI))
		{
				TRPF = Zero
		}

		Return (SMIF) /* \SMIF */
}

OperationRegion (IO_D, SystemIO, 0x0810, 0x04)
Field (IO_D, ByteAcc, NoLock, Preserve)
{
		TRPD,   8
}

OperationRegion (IO_H, SystemIO, 0x1000, 0x04)
Field (IO_H, ByteAcc, NoLock, Preserve)
{
		TRPH,   8
}

OperationRegion (IO_P, SystemIO, 0x1000, 0x04)
Field (IO_P, ByteAcc, NoLock, Preserve)
{
		TRPF,   8
}

OperationRegion (PRT0, SystemIO, 0x80, 0x04)
Field (PRT0, DWordAcc, Lock, Preserve)
{
		P80H,   32
}

Method (P8XH, 2, Serialized)
{
		If ((Arg0 == Zero))
		{
				P80D = ((P80D & 0xFFFFFF00) | Arg1)
		}

		If ((Arg0 == One))
		{
				P80D = ((P80D & 0xFFFF00FF) | (Arg1 << 0x08))
		}

		If ((Arg0 == 0x02))
		{
				P80D = ((P80D & 0xFF00FFFF) | (Arg1 << 0x10))
		}

		If ((Arg0 == 0x03))
		{
				P80D = ((P80D & 0x00FFFFFF) | (Arg1 << 0x18))
		}

		P80H = P80D /* \P80D */
}


OperationRegion (GNVS, SystemMemory, 0xCA7FCC18, 0x02B4)
Field (GNVS, AnyAcc, Lock, Preserve)
{
		AAAA,   16, 
		AAAC,   8, 
		PRM0,   8, 
		PRM1,   8, 
		AAAD,   8, 
		PRM2,   8, 
		PRM3,   8, 
		LCKF,   8, 
		PRM4,   8, 
		PRM5,   8, 
		AAAE,   32, 
		AAAB,   8, 
		DBGS,   8, 
		THOF,   8, 
		ACT1,   8, 
		ACTT,   8, 
		PSVT,   8, 
		TC1V,   8, 
		TC2V,   8, 
		TSPV,   8, 
		CRTT,   8, 
		DTSE,   8, 
		DTS1,   8, 
		DTS2,   8, 
		DTSF,   8, 
		Offset (0x1E), 
		Offset (0x25), 
		REVN,   8, 
		Offset (0x28), 
		APIC,   8, 
		TCNT,   8, 
		AAAF,   8, 
		AAAG,   8, 
		AAAH,   8, 
		PPMF,   32, 
		C67L,   8, 
		AAAI,   8, 
		CMAP,   8, 
		CMBP,   8, 
		LPTP,   8, 
		FDCP,   8, 
		CMCP,   8, 
		CIRP,   8, 
		SMSC,   8, 
		W381,   8, 
		SMC1,   8, 
		EMAE,   8, 
		EMAP,   16, 
		EMAL,   16, 
		Offset (0x42), 
		MEFE,   8, 
		DSTS,   8, 
		Offset (0x48), 
		MORD,   8, 
		TCGP,   8, 
		PPRP,   32, 
		PPRQ,   8, 
		LPPR,   8, 
		GTF0,   56, 
		GTF2,   56, 
		IDEM,   8, 
		GTF1,   56, 
		BID,    16, 
		PLID,   8, 
		ECTG,   8, 
		Offset (0x70), 
		OSCC,   8, 
		NEXP,   8, 
		SBV1,   8, 
		SBV2,   8, 
		Offset (0x7A), 
		DSEN,   8, 
		ECON,   8, 
		GPIC,   8, 
		CTYP,   8, 
		L01C,   8, 
		VFN0,   8, 
		VFN1,   8, 
		VFN2,   8, 
		VFN3,   8, 
		VFN4,   8, 
		VFN5,   8, 
		VFN6,   8, 
		VFN7,   8, 
		VFN8,   8, 
		VFN9,   8, 
		Offset (0x8F), 
		ATMC,   8, 
		PTMC,   8, 
		ATRA,   8, 
		PTRA,   8, 
		PNHM,   32, 
		TBAB,   32, 
		TBAH,   32, 
		RTIP,   8, 
		TSOD,   8, 
		ATPC,   8, 
		PTPC,   8, 
		PFLV,   8, 
		BREV,   8, 
		PDTS,   8, 
		PKGA,   8, 
		PAMT,   8, 
		AC0F,   8, 
		AC1F,   8, 
		DTS3,   8, 
		DTS4,   8, 
		Offset (0xB0), 
		LTR1,   8, 
		LTR2,   8, 
		LTR3,   8, 
		LTR4,   8, 
		LTR5,   8, 
		LTR6,   8, 
		LTR7,   8, 
		LTR8,   8, 
		OBF1,   8, 
		OBF2,   8, 
		OBF3,   8, 
		OBF4,   8, 
		OBF5,   8, 
		OBF6,   8, 
		OBF7,   8, 
		OBF8,   8, 
		XHCI,   8, 
		XTUB,   32, 
		XTUS,   32, 
		XMPB,   32, 
		DDRF,   8, 
		RTD3,   8, 
		PEP0,   8, 
		PEP3,   8, 
		DPTF,   8, 
		SADE,   8, 
		SACR,   8, 
		SAHT,   8, 
		PCHD,   8, 
		PCHC,   8, 
		PCHH,   8, 
		CTDP,   8, 
		LPMP,   8, 
		LPMV,   8, 
		ECEU,   8, 
		TGFG,   16, 
		MEMD,   8, 
		MEMC,   8, 
		MEMH,   8, 
		FND1,   8, 
		FND2,   8, 
		AMBD,   8, 
		AMAT,   8, 
		AMPT,   8, 
		AMCT,   8, 
		AMHT,   8, 
		SKDE,   8, 
		SKAT,   8, 
		SKPT,   8, 
		SKCT,   8, 
		SKHT,   8, 
		EFDE,   8, 
		EFAT,   8, 
		EFPT,   8, 
		EFCT,   8, 
		EFHT,   8, 
		VRDE,   8, 
		VRAT,   8, 
		VRPT,   8, 
		VRCT,   8, 
		VRHT,   8, 
		DPAP,   8, 
		DPPP,   8, 
		DPCP,   8, 
		DCMP,   8, 
		TRTV,   8, 
		LPOE,   8, 
		LPOP,   8, 
		LPOS,   8, 
		LPOW,   8, 
		LPER,   8, 
		PPSZ,   32, 
		DISE,   8, 
		PFMA,   64, 
		PFMS,   8, 
		PFIA,   16, 
		ICNF,   8, 
		DSP0,   32, 
		DSP1,   32, 
		NFCE,   8, 
		CODS,   8, 
		SNHE,   8, 
		S0ID,   8, 
		CTDB,   8, 
		Offset (0x206), 
		STME,   8, 
		PWRE,   8, 
		PWRP,   8, 
		XHPR,   8, 
		SDS0,   8, 
		SDS1,   16, 
		SDS2,   8, 
		SDS3,   8, 
		SDS4,   8, 
		SDS5,   8, 
		Offset (0x212), 
		RIC0,   8, 
		PEPY,   8, 
		DVS0,   8, 
		DVS1,   8, 
		DVS2,   8, 
		DVS3,   8, 
		GBSX,   8, 
		IUBE,   8, 
		IUCE,   8, 
		IUDE,   8, 
		ECNO,   8, 
		AUDD,   16, 
		DSPD,   16, 
		IC0D,   16, 
		IC1D,   16, 
		IC1S,   16, 
		VRRD,   16, 
		PSCP,   8, 
		RWAG,   8, 
		I20D,   16, 
		I21D,   16, 
		Offset (0x231), 
		RCG0,   8, 
		ECDB,   8, 
		P2ME,   8, 
		SSH0,   16, 
		SSL0,   16, 
		SSD0,   16, 
		FMH0,   16, 
		FML0,   16, 
		FMD0,   16, 
		FPH0,   16, 
		FPL0,   16, 
		FPD0,   16, 
		SSH1,   16, 
		SSL1,   16, 
		SSD1,   16, 
		FMH1,   16, 
		FML1,   16, 
		FMD1,   16, 
		FPH1,   16, 
		FPL1,   16, 
		FPD1,   16, 
		M0C0,   16, 
		M1C0,   16, 
		M2C0,   16, 
		M0C1,   16, 
		M1C1,   16, 
		M2C1,   16, 
		M0C2,   16, 
		M1C2,   16, 
		M0C3,   16, 
		M1C3,   16, 
		M0C4,   16, 
		M1C4,   16, 
		M0C5,   16, 
		M1C5,   16, 
		TBSF,   8, 
		GIRQ,   32, 
		DMTP,   8, 
		DMTD,   8, 
		DMSH,   8, 
		LANP,   8, 
		Offset (0x27E), 
		SHSB,   8, 
		PLCS,   8, 
		PLVL,   16, 
		GN1E,   8, 
		G1AT,   8, 
		G1PT,   8, 
		G1CT,   8, 
		G1HT,   8, 
		GN2E,   8, 
		G2AT,   8, 
		G2PT,   8, 
		G2CT,   8, 
		G2HT,   8, 
		WWSD,   8, 
		CVSD,   8, 
		SSDD,   8, 
		INLD,   8, 
		IFAT,   8, 
		IFPT,   8, 
		IFCT,   8, 
		IFHT,   8, 
		DOSD,   8, 
		USBH,   8, 
		BCV4,   8, 
		WTV0,   8, 
		WTV1,   8, 
		APFU,   8, 
		SOHP,   8, 
		NOHP,   8, 
		TBSE,   8, 
		WKFN,   8, 
		PEPC,   16, 
		VRSD,   16, 
		PB1E,   8, 
		WAND,   8, 
		WWAT,   8, 
		WWPT,   8, 
		WWCT,   8, 
		WWHT,   8, 
		Offset (0x2AD), 
		MPLT,   16, 
		GR13,   8, 
		SPST,   8, 
		ECLP,   8, 
		E4GM,   8, 
		HFSE,   8
}
