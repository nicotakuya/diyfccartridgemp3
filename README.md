# Mapper3 test program for Famicom

## Overview
![screenshot](https://github.com/nicotakuya/diyfccartridgemp3/assets/5597377/1b25f838-36d2-45ca-88fc-a25b219e9974)

バンク切り替えの実験をするプログラムです。

ボタンを押すとバンク（0～3）が切り替わります。

## How to build

開発環境はCC65です。build.batを実行すると、nesファイルが作成されます。

実機で動かすにはMapper3のカートリッジが必要です。
CHR-ROMにはパターンのデータ（32KB）、PRG-ROMにはプログラム（32KB）をそれぞれ書き込みます。

![memorymap](https://github.com/nicotakuya/diyfccartridgemp3/assets/5597377/053513bc-3467-4bbb-b5cb-9e4dabfcfe88)

## Movie

https://www.youtube.com/watch?v=RNkaBpNNFIM
