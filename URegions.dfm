object FRegions: TFRegions
  Left = 0
  Top = 0
  Caption = #1056#1077#1075#1080#1086#1085#1099
  ClientHeight = 276
  ClientWidth = 490
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesktopCenter
  OnShow = FormShow
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 490
    Height = 41
    Align = alTop
    TabOrder = 0
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 41
    Width = 490
    Height = 210
    Align = alClient
    DataSource = DataModule2.DataSource10
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 251
    Width = 490
    Height = 25
    Panels = <
      item
        Alignment = taCenter
        Width = 50
      end>
  end
  object Button3: TButton
    Left = 194
    Top = 0
    Width = 95
    Height = 40
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button2: TButton
    Left = 98
    Top = 0
    Width = 95
    Height = 40
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button1: TButton
    Left = 0
    Top = 0
    Width = 97
    Height = 40
    Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 5
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 329
    Top = 8
    Width = 152
    Height = 23
    TabOrder = 6
    Text = #1055#1086#1080#1089#1082'...'
    OnChange = Edit1Change
    OnEnter = Edit1Enter
    OnExit = Edit1Exit
  end
end
