object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 203
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object ButtonOK: TButton
    Left = 273
    Top = 164
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = ButtonOKClick
  end
  object cxTextEditPathConfig: TcxTextEdit
    Left = 16
    Top = 49
    TabOrder = 1
    Width = 553
  end
  object ButtonSearchFolder: TButton
    Left = 567
    Top = 49
    Width = 35
    Height = 24
    Caption = '...'
    TabOrder = 2
    OnClick = ButtonSearchFolderConfig
  end
  object StaticTextConfigFile: TStaticText
    Left = 16
    Top = 24
    Width = 204
    Height = 19
    Caption = 'Ruta archivo configuraci'#243'n (Doxyfile):'
    TabOrder = 3
  end
  object StaticText1: TStaticText
    Left = 16
    Top = 96
    Width = 105
    Height = 19
    Caption = 'Ruta archivos C++:'
    TabOrder = 4
  end
  object cxTextEditPathFiles: TcxTextEdit
    Left = 16
    Top = 121
    TabOrder = 5
    Width = 553
  end
  object ButtonSearchFiles: TButton
    Left = 567
    Top = 120
    Width = 35
    Height = 25
    Caption = '...'
    TabOrder = 6
    OnClick = ButtonSearchFolderFiles
  end
  object CheckBoxUML: TCheckBox
    Left = 24
    Top = 168
    Width = 97
    Height = 17
    Hint = 
      'Visualiza los diagramas de clases con un estilo similar al Lengu' +
      'aje Unificado de Modelado (UML). Se utiliza la herrmaienta [I]do' +
      't[/I] de Graphviz (tiene que estar en el [B]PATH[/B]).'
    Caption = 'Diagrama UML'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 7
    OnClick = CheckBoxUMLClick
  end
end
