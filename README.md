# プロジェクトタイトル

42_push_swap

## 概要

限られた命令セットと最小限の移動数を使用して、スタック上のデータを並べ替えます。

## 動機

42Tokyoの課題であり、また、  
最短での入れ替えアルゴリズムを模索し、  
双方向リストの使い方を理解するため、実装できるよう作成しました。

## 使用方法

> - **normal**
> ```bash php
> #!/bin/bash
> cd 42_push_swap
> make
> ./push_swap "(任意の数字列)"
> ```

> - **例**  
> ```bash php  
> #!/bin/bash  
> ./push_swap "2 1 3"  
> sa(このような出力が期待されます)
> ```


> - **ランダムな数のテスト**  
> [テスター をダウンロード](https://projects.intra.42.fr/projects/42cursus-push_swap#:~:text=subject.pdf-,checker_Mac,-checker_linux)

> 42_push_swapの直下にダウンロードしてきたファイルを配置してください。
> ```bash php  
> #!/bin/bash  
> ARG=$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $ARG | ./checker_Mac $ARG
> ```


## 技術スタック

C言語
