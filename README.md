# Arcaduino
Controle Arcade/Fliperama feito com 8 botões, um direcional e um Arduino Leonardo

As explicações estão todas no próprio código, através de comentários, incluindo nome dos botões e código de cores para os fios (jumpers ou soldados num pin header).

A montagem do projeto foi baseado na numeração dos botões dos controles USB genéricos de SNES e PS2, testados a partir do site: https://gamepad-tester.com/

Funcionando em Raspberry Pi usando Lakka e Retropie (configurar segundo os botões do SNES e segundo esquema no código), assim como no MAME e FBAlpha e FBNEO para PC.

Atualização: Tive de incluir no código um botão extra, feito com jumper cables (sem alterar a configuração estética do controle), pois Lakka estava mapeando a Configuração do Mame no botão Select (Ficha/Coin) do controle arcade. 

Criei esse botão virtual com Jumper Cables para fazer a configuração no Lakka. Está ligado na entrada A0 e no Ground logo acima na placa Leonardo.
