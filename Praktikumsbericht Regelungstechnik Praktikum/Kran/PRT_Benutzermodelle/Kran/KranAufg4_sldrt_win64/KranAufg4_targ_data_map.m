  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (KranAufg4_P)
    ;%
      section.nData     = 55;
      section.data(55)  = dumData; %prealloc
      
	  ;% KranAufg4_P.Kpa
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KranAufg4_P.Kpy
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% KranAufg4_P.pooled1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% KranAufg4_P.T_S
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% KranAufg4_P.Constant3_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% KranAufg4_P.Constant2_Value
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% KranAufg4_P.Constant1_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% KranAufg4_P.Constant_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% KranAufg4_P.Encoder_P1_Size
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% KranAufg4_P.Encoder_P1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% KranAufg4_P.Encoder500PPR_Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% KranAufg4_P.XScale_Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% KranAufg4_P.YScale_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% KranAufg4_P.ZScale_Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% KranAufg4_P.Constant_Value_g
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 16;
	
	  ;% KranAufg4_P.Constant3_Value_o
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 17;
	
	  ;% KranAufg4_P.DiscreteTransferFcn_NumCoef
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 18;
	
	  ;% KranAufg4_P.DiscreteTransferFcn_DenCoef
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 20;
	
	  ;% KranAufg4_P.DiscreteTransferFcn_InitialStates
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 22;
	
	  ;% KranAufg4_P.Saturation_UpperSat
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% KranAufg4_P.Saturation_LowerSat
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 24;
	
	  ;% KranAufg4_P.YAngleScale_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 25;
	
	  ;% KranAufg4_P.Constant2_Value_p
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 26;
	
	  ;% KranAufg4_P.DiscreteTransferFcn_NumCoef_j
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 27;
	
	  ;% KranAufg4_P.DiscreteTransferFcn_DenCoef_a
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 29;
	
	  ;% KranAufg4_P.DiscreteTransferFcn_InitialStates_a
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 31;
	
	  ;% KranAufg4_P.Constant1_Value_o
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 32;
	
	  ;% KranAufg4_P.LimitSwitch_P1_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 33;
	
	  ;% KranAufg4_P.LimitSwitch_P1
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 35;
	
	  ;% KranAufg4_P.LimitSwitchGain_Gain
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 36;
	
	  ;% KranAufg4_P.XAngleScale_Gain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 37;
	
	  ;% KranAufg4_P.Switch_Threshold
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 38;
	
	  ;% KranAufg4_P.Switch1_Threshold
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 39;
	
	  ;% KranAufg4_P.PWM_P1_Size
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 40;
	
	  ;% KranAufg4_P.PWM_P1
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 42;
	
	  ;% KranAufg4_P.Saturation_UpperSat_n
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 43;
	
	  ;% KranAufg4_P.Saturation_LowerSat_n
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 44;
	
	  ;% KranAufg4_P.LimitFlag_P1_Size
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 45;
	
	  ;% KranAufg4_P.LimitFlag_P1
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 47;
	
	  ;% KranAufg4_P.LimitFlagSource_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 48;
	
	  ;% KranAufg4_P.LimitSource_Value
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 51;
	
	  ;% KranAufg4_P.SetLimit_P1_Size
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 54;
	
	  ;% KranAufg4_P.SetLimit_P1
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 56;
	
	  ;% KranAufg4_P.PWMPrescaler_P1_Size
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 57;
	
	  ;% KranAufg4_P.PWMPrescaler_P1
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 59;
	
	  ;% KranAufg4_P.PWMPrescalerSource_Value
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 60;
	
	  ;% KranAufg4_P.ResetEncoder_P1_Size
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 61;
	
	  ;% KranAufg4_P.ResetEncoder_P1
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 63;
	
	  ;% KranAufg4_P.ResetSource_Value
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 64;
	
	  ;% KranAufg4_P.ResetSwitchFlag_P1_Size
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 69;
	
	  ;% KranAufg4_P.ResetSwitchFlag_P1
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 71;
	
	  ;% KranAufg4_P.ResetSwitchFlagSource_Value
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 72;
	
	  ;% KranAufg4_P.ThermFlag_P1_Size
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 75;
	
	  ;% KranAufg4_P.ThermFlag_P1
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 77;
	
	  ;% KranAufg4_P.ThermFlagSource_Value
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 78;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (KranAufg4_B)
    ;%
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% KranAufg4_B.Encoder
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KranAufg4_B.XScale
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% KranAufg4_B.YScale
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% KranAufg4_B.ZScale
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% KranAufg4_B.ux
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% KranAufg4_B.YAngleScale
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 9;
	
	  ;% KranAufg4_B.uy
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 10;
	
	  ;% KranAufg4_B.Constant1
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 11;
	
	  ;% KranAufg4_B.LimitSwitch
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 12;
	
	  ;% KranAufg4_B.LimitSwitchGain
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 15;
	
	  ;% KranAufg4_B.XAngleScale
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 18;
	
	  ;% KranAufg4_B.Switch
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 19;
	
	  ;% KranAufg4_B.Switch1
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 20;
	
	  ;% KranAufg4_B.PWM
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 21;
	
	  ;% KranAufg4_B.Saturation
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 24;
	
	  ;% KranAufg4_B.LimitFlag
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 27;
	
	  ;% KranAufg4_B.LimitFlagSource
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 30;
	
	  ;% KranAufg4_B.LimitSource
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 33;
	
	  ;% KranAufg4_B.SetLimit
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 36;
	
	  ;% KranAufg4_B.PWMPrescaler
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 39;
	
	  ;% KranAufg4_B.PWMPrescalerSource
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 40;
	
	  ;% KranAufg4_B.ResetEncoder
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 41;
	
	  ;% KranAufg4_B.ResetSource
	  section.data(23).logicalSrcIdx = 24;
	  section.data(23).dtTransOffset = 46;
	
	  ;% KranAufg4_B.ResetSwitchFlag
	  section.data(24).logicalSrcIdx = 25;
	  section.data(24).dtTransOffset = 51;
	
	  ;% KranAufg4_B.ResetSwitchFlagSource
	  section.data(25).logicalSrcIdx = 26;
	  section.data(25).dtTransOffset = 54;
	
	  ;% KranAufg4_B.ThermFlag
	  section.data(26).logicalSrcIdx = 27;
	  section.data(26).dtTransOffset = 57;
	
	  ;% KranAufg4_B.ThermFlagSource
	  section.data(27).logicalSrcIdx = 28;
	  section.data(27).dtTransOffset = 60;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (KranAufg4_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% KranAufg4_DW.DiscreteTransferFcn_states
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KranAufg4_DW.DiscreteTransferFcn_states_n
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% KranAufg4_DW.DiscreteTransferFcn_tmp
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% KranAufg4_DW.DiscreteTransferFcn_tmp_e
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% KranAufg4_DW.Position_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KranAufg4_DW.Stellsignal_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% KranAufg4_DW.Switches_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% KranAufg4_DW.Winkel_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% KranAufg4_DW.Scope_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2104128675;
  targMap.checksum1 = 3964254063;
  targMap.checksum2 = 3061114180;
  targMap.checksum3 = 2804016967;

