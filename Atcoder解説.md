## ACした問題たちについて解説

* ABC140 D Face Produces Unhappiness
    > 数列圧縮 <br>
    > LRの配列を0-1compressionして一回回すあたり最大2つDisjointが消せることに気づけば解ける

* TOITESU C Different Strokes
    > シグマの中抜け・式変形 <br>
    > 幸福度は sigma(自分の皿) - sigma(相手の皿) <- 目的関数 <br>
    > 変形して sigma(全部の皿[自分+相手]) - sigma(相手の皿[自分+相手]) - sigma(全部の皿[相手]) <br>
    > 従って sigma(自分の皿[自分+相手]) - sigma(全部の皿[相手])

* AGC038 A 01 Matrix
    > 出力行列をゼロのみの行列・１のみの行列にすれば構成可能

* ABC154 E Almost Everywhere Zero
    > 10**100とアホでかいのでdpを考える <br>
    > 1.    dp[i][j][k] で下からi桁目について，その桁がjのとき，（そのj桁を含めて）ゼロでない数が何個あるか，をdp配列に記憶させる iをメインループで回して前処理 <br>
    > あとはs = input()で貰った数を，大きい桁から足し合わせてゆけば解ける <br>
    > 2.   ## 桁dpという解法があるらしい <br>
    > 大きい桁からN以下となるようにdpで決めてゆく，このときNより確実に小さい/Nより小さいかもで２つdpテーブルを作って，10**0桁目で辻褄を合わせれば解ける