object FCoupons: TFCoupons
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1058#1072#1083#1086#1085#1099
  ClientHeight = 448
  ClientWidth = 787
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnShow = FormShow
  TextHeight = 15
  object Panel1: TPanel
    Left = 591
    Top = 46
    Width = 196
    Height = 402
    Align = alRight
    TabOrder = 0
    object Panel4: TPanel
      Left = 1
      Top = 193
      Width = 194
      Height = 208
      Align = alClient
      TabOrder = 0
      object TreeView1: TTreeView
        Left = 1
        Top = 1
        Width = 192
        Height = 206
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        HideSelection = False
        Indent = 19
        ParentFont = False
        TabOrder = 0
        OnClick = TreeView1Click
      end
    end
    object Panel5: TPanel
      Left = 1
      Top = 1
      Width = 194
      Height = 192
      Align = alTop
      TabOrder = 1
      object MonthCalendar1: TMonthCalendar
        Left = 1
        Top = 1
        Width = 192
        Height = 190
        Align = alClient
        Date = 45638.000000000000000000
        TabOrder = 0
        OnClick = MonthCalendar1Click
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 46
    Width = 591
    Height = 402
    Align = alClient
    TabOrder = 1
    object DBGrid1: TDBGrid
      Left = 1
      Top = 1
      Width = 589
      Height = 286
      Align = alClient
      DataSource = DataModule2.DataSource5
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -12
      TitleFont.Name = 'Segoe UI'
      TitleFont.Style = []
    end
    object Memo1: TMemo
      Left = 1
      Top = 287
      Width = 589
      Height = 89
      Align = alBottom
      Lines.Strings = (
        'Memo1')
      TabOrder = 1
    end
    object StatusBar1: TStatusBar
      Left = 1
      Top = 376
      Width = 589
      Height = 25
      Panels = <
        item
          Alignment = taCenter
          Width = 50
        end>
    end
  end
  object Panel6: TPanel
    Left = 0
    Top = 0
    Width = 787
    Height = 46
    Align = alTop
    TabOrder = 2
    object Button1: TButton
      Left = 8
      Top = 2
      Width = 97
      Height = 41
      Caption = #1055#1088#1086#1074#1077#1089#1090#1080#13#10' '#1087#1088#1080#1077#1084
      TabOrder = 0
      WordWrap = True
      OnClick = Button1Click
    end
    object Button3: TButton
      Left = 111
      Top = 1
      Width = 90
      Height = 41
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100#13#10' '#1079#1072#1087#1080#1089#1100
      TabOrder = 1
      WordWrap = True
      OnClick = Button3Click
    end
    object CheckBox1: TCheckBox
      Left = 631
      Top = 16
      Width = 113
      Height = 17
      Caption = #1055#1088#1080#1077#1084' '#1087#1088#1086#1074#1077#1076#1077#1085
      TabOrder = 2
      OnClick = CheckBox1Click
    end
    object Button2: TButton
      Left = 207
      Top = 0
      Width = 90
      Height = 41
      Caption = #1059#1076#1072#1083#1080#1090#1100#13#10' '#1079#1072#1087#1080#1089#1100
      TabOrder = 3
      WordWrap = True
      OnClick = Button2Click
    end
  end
end
