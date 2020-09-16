## ACした問題たちについて解説

* ABC140 D Face Produces Unhappiness
    > 数列圧縮 <br>
    > LRの配列を0-1compressionして一回回すあたり最大2つDisjointが消せることに気づけば解ける

* TOITESU C Different Strokes
    > シグマの中抜け・式変形 <br>
    > 幸福度は sigma(自分の皿) - sigma(相手の皿) <- 目的関数 <br>
    > 変形して sigma(全部の皿[自分+相手]) - sigma(相手の皿[自分+相手]) - sigma(全部の皿[相手]) <br>
    > 従って sigma(自分の皿[自分+相手]) - sigma(全部の皿[相手])
