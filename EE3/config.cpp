class CfgPatches
{
	class UL_Weapons_EE3
	{
		addonRootClass=UL_Weapons;
		units[]={};
		weapons[]={
			"UL_Weapons_EE3"
		};
        magazines[]={
			"UL_Weapons_EE3_Mag"
		};
		ammo[]={
			"UL_Weapons_EE3_Ammo"
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Weapons_F"
		};
	};
	author="UnluckyLoki";
};

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

/// Weapon slots
class SlotInfo;
class MuzzleSlot;
class CowsSlot;
class PointerSlot;
class UnderBarrelSlot;

class CfgWeapons
{
	class Rifle;
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class UGL_F;

	class UL_Weapons_EE3: Rifle_Base_F /// Just basic values common for all testing rifle variants
	{
        scope=2;
		displayName="[UL] EE-3 Carabine (black)";
		model="\UL_Weapons\EE3\EE3.p3d";
		hiddenSelections[] = {"camo1","camo2","camo3"};
		hiddenSelectionsTextures[]={
			"\UL_Weapons\EE3\tex\EE3_1_CO.paa",
			"\UL_Weapons\EE3\tex\EE3_2_CO.paa",
			"\UL_Weapons\EE3\tex\EE3_1_CO.paa"
		};
		hiddenSelectionsMaterials[]={
			"\UL_Weapons\EE3\tex\EE3_main.rvmat",
			"\UL_Weapons\EE3\tex\EE3_stock.rvmat",
			"\UL_Weapons\EE3\tex\EE3_scope.rvmat"
		};
		picture="\UL_Weapons\EE3\tex\EE3_black_ui.paa";
		magazines[]={"UL_Weapons_EE3_Mag"};
		reloadAction="GestureReloadMX"; /// MX hand animation actually fits this rifle well
		handAnim[]={
			"OFP2_ManSkeleton",
			"\UL_Weapons\EE3\anim\ee3_handanim.rtm" // \SWLW_clones\rifles\dc15x\anims\dc15x_handanim.rtm
		};
		magazineReloadSwitchPhase=0.4; /// part of reload animation when new magazine ammo count should affect "revolving" animation source
		discreteDistanceInitIndex=0;
		maxRecoilSway=0.0125;
        swayDecaySpeed=1.25;
		inertia=0.5;
		initSpeed=-1;
		class GunParticles
		{
			class FirstEffect
			{
				directionName="konec hlavne";
				effectName="RifleAssaultCloud";
				positionName="usti hlavne";
			};
		};

		class WeaponSlotsInfo: WeaponSlotsInfo{
            mass = 40;
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {""}; 				                /// A custom made suppressor for this weapon
				iconPosition[] = {0.0, 0.45};							/// position of the slot icon inside of the weapon icon, relative to top-left corner in {right, down} format
				iconScale = 0.2;										/// scale of icon described in iconPicture
			};
			class CowsSlot: CowsSlot /// default accessories for this slot
			{
				compatibleItems[] = {""}; 
				iconPosition[] = {0.5, 0.35};
				iconScale = 0.2;
			};
			class PointerSlot: PointerSlot /// default accessories for this slot
			{
				compatibleItems[] = {""}; 
				iconPosition[] = {0.20, 0.45};
				iconScale = 0.25;
			};
			class UnderBarrelSlot: UnderBarrelSlot /// using test bipod
			{
				compatibleItems[] = {""}; 
				iconPosition[] = {0.2, 0.7};
				iconScale = 0.2;
			};
		};
		descriptionShort="EE-3 Carabine";
		modelOptics="\A3\Weapons_f\acc\reticle_TWS.p3d"; //modelOptics="\UL_Weapons\EE3\sight\A3_2d_optic_marksmen.p3d";
		maxZeroing=2000;
		opticsZoomMin=0.1;
		opticsZoomMax=1.25;
		opticsZoomInit=1;
		distanceZoomMin=100;
		distanceZoomMax=2000;
		weaponInfoType="";
		visionMode[]={
			"Normal",
			"NVG",
			"TI"
		};
		thermalMode[]={0,2};
		opticsFlare=1;
		hasbipod=1;
		caseless[]={
			"",
			1,
			1,
			1
		};
		soundBullet[]={
			"caseless",
			1
		};
		modes[]={"Single","FullAuto"};
		//selectionFireAnim="zasleh";
		//flash="gunfire";
		//flashSize=0.5;
		//fireLightIntensity=0.02;
		//fireLightDuration=0.050000001;
		

		class FullAuto: Mode_FullAuto
		{
			sounds[]={
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType
			{
				begin1[]=
				{
					"UL_Weapons\EE3\ee3.wav",
					1,
					1,
					500
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
            reloadTime = 0.25;
			dispersion = 0;

			//recoil = "EE3_recoil";
			//recoilProne = "EE3_recoil";

			minRange = 2; minRangeProbab = 0.5; 	/// Task Force Balance black magic - this is the probability which AI thinks it would hit target at set range with
			midRange = 200; midRangeProbab = 0.7; 	/// it is no real probability of hit, just used for AI to compute if the shot is worth to take - AI chooses highest
			maxRange = 400; maxRangeProbab = 0.3; 
        };
		

		class Single: Mode_SemiAuto
		{
			sounds[]={
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType
			{
				begin1[]=
				{
					"UL_Weapons\EE3\ee3.wav",
					1,
					1,
					500
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
            reloadTime = 0.25;
			dispersion = 0;

			//recoil = "EE3_recoil"; /// defined in cfgRecoils
			//recoilProne = "EE3_recoil"; /// defined in cfgRecoils

			minRange = 2; minRangeProbab = 0.5; 	/// Task Force Balance black magic - this is the probability which AI thinks it would hit target at set range with
			midRange = 200; midRangeProbab = 0.7; 	/// it is no real probability of hit, just used for AI to compute if the shot is worth to take - AI chooses highest
			maxRange = 400; maxRangeProbab = 0.3; 
        };
    };

	class UL_Weapons_EE3_cream:UL_Weapons_EE3{
		displayName="[UL] EE-3 Carabine (cream)";
		hiddenSelectionsTextures[]={
			"\UL_Weapons\EE3\tex\EE3_1_CO.paa",
			"\UL_Weapons\EE3\tex\EE3_cream_2_CO.paa",
			"\UL_Weapons\EE3\tex\EE3_1_CO.paa"
		};
		picture="\UL_Weapons\EE3\tex\EE3_cream_ui.paa";
	};
};

class CfgMagazines{
	class 7Rnd_408_Mag;
	class UL_Weapons_EE3_Mag:7Rnd_408_Mag{
		displayName="[UL] EE-3 40rnd Charge Cell";
		descriptionShort="40 rounds charge cell for EE-3 carabine";
		mass=8;
		count=40;
		tracersEvery=1;
		initSpeed=900;
		lastRoundTracer=200;
		picture="\UL_Weapons\EE3\tex\EE3_mag_ui.paa";
		ammo="UL_Weapons_EE3_Ammo";
	};
};

class CfgAmmo{
	class JLTS_bullet_pistol_red;
	class UL_Weapons_EE3_Ammo:JLTS_bullet_pistol_red{
		hit=45;
		caliber=2;
		coefGravity=0;
		deflecting=0;
		airFriction=0;
		typicalSpeed=900;
	};
};

class cfgRecoils{
	#include "cfgRecoilsLegacy.hpp"
	class Default;
	//	muzzleOuter[]	= x,y,a,b = { horizontal axis, vertical axis, horizontal magnitude, vertical magnitude }; plot: ((p+x)/a)^2 + ((q+y)/b)^2 = 1;
	//	muzzleInner[]	= x,y,a,b = { horizontal axis, vertical axis, horizontal magnitude, vertical magnitude }; plot: ((p+x)/a)^2 + ((q+y)/b)^2 = 1;
	//	kickBack[]		= min&max = { minimum, maximum };

	class recoil_default: Default{
						//	x_		y|		a>		b^
		muzzleOuter[]	= { 0.3,	1.0,	0.3,	0.2 };
		muzzleInner[]	= { 0,		0,		0.1,	0.1	};
		kickBack[]		= { 0.03,	0.06 };
		permanent		= 0.1;
		temporary		= 0.01;
	};

	class EE3_recoil: recoil_default{
		muzzleOuter[] = {0.5, 1.0, 0.4, 0.5};
		muzzleInner[] = {0, 0, 0.2, 0.2};
		kickBack[] = {0.04, 0.06};
		temporary = 0.01;
	};
};

class CfgCloudlets{
};