object Form4: TForm4
  Left = 0
  Top = 0
  Caption = #1056#1072#1089#1095#1077#1090' '#1082#1072#1083#1086#1088#1080#1081
  ClientHeight = 342
  ClientWidth = 322
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 52
    Top = 29
    Width = 35
    Height = 21
    Caption = #1055#1086#1083':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 47
    Top = 80
    Width = 40
    Height = 21
    Caption = #1056#1086#1089#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 54
    Top = 120
    Width = 33
    Height = 21
    Caption = #1042#1077#1089':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 23
    Top = 165
    Width = 67
    Height = 21
    Caption = #1042#1086#1079#1088#1072#1089#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 74
    Top = 210
    Width = 159
    Height = 21
    Caption = #1059#1088#1086#1074#1077#1085#1100' '#1072#1082#1090#1080#1074#1085#1086#1089#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object ComboBox1: TComboBox
    Left = 96
    Top = 29
    Width = 145
    Height = 21
    TabOrder = 0
    Text = #1055#1086#1083
    Items.Strings = (
      #1052#1091#1078#1089#1082#1086#1081
      #1046#1077#1085#1089#1082#1080#1081)
  end
  object Edit1: TEdit
    Left = 96
    Top = 80
    Width = 145
    Height = 21
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 1
  end
  object Edit2: TEdit
    Left = 96
    Top = 123
    Width = 145
    Height = 21
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 2
  end
  object Edit3: TEdit
    Left = 96
    Top = 165
    Width = 145
    Height = 21
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 3
  end
  object ComboBox2: TComboBox
    Left = 17
    Top = 238
    Width = 289
    Height = 21
    TabOrder = 4
    Text = #1059#1088#1086#1074#1077#1085#1100' '#1072#1082#1090#1080#1074#1085#1086#1089#1090#1080
    Items.Strings = (
      #1084#1080#1085#1080#1084#1072#1083#1100#1085#1099#1081' '#1091#1088#1086#1074#1077#1085#1100' ('#1085#1080#1082#1072#1082#1080#1093' '#1092#1080#1079#1080#1095#1077#1089#1082#1080#1093' '#1085#1072#1075#1088#1091#1079#1086#1082')'
      #1085#1080#1079#1082#1080#1081' ('#1092#1080#1079#1080#1095#1077#1089#1082#1080#1077' '#1085#1072#1075#1088#1091#1079#1082#1080' 1-3 '#1088#1072#1079#1072' '#1074' '#1085#1077#1076#1077#1083#1102')'
      #1089#1088#1077#1076#1085#1080#1081' (3-5 '#1076#1085#1077#1081' '#1074' '#1085#1077#1076#1077#1083#1102')'
      #1074#1099#1089#1086#1082#1080#1081' (6-7 '#1088#1072#1079' '#1074' '#1085#1077#1076#1077#1083#1102')'
      #1086#1095#1077#1085#1100' '#1074#1099#1089#1086#1082#1080#1081' ('#1090#1088#1077#1085#1080#1088#1086#1074#1082#1080' '#1095#1072#1097#1077', '#1095#1077#1084' '#1088#1072#1079' '#1074' '#1076#1077#1085#1100')')
  end
  object Button1: TButton
    Left = 112
    Top = 280
    Width = 97
    Height = 38
    Caption = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100
    TabOrder = 5
    OnClick = Button1Click
  end
end
