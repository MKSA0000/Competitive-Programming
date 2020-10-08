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
    > 出力行列をゼロのみの行列・１のみの行列にすれば構成可能　<br>

* ABC154 E Almost Everywhere Zero
    > 10**100とアホでかいのでdpを考える <br>
    > 1.    dp[i][j][k] で下からi桁目について，その桁がjのとき，（そのj桁を含めて）ゼロでない数が何個あるか，をdp配列に記憶させる iをメインループで回して前処理 <br>
    > あとはs = input()で貰った数を，大きい桁から足し合わせてゆけば解ける <br>
    > 2.   ## 桁dpという解法があるらしい <br>
    > 大きい桁からN以下となるようにdpで決めてゆく，このときNより確実に小さい/Nより小さいかもで２つdpテーブルを作って，10**0桁目で辻褄を合わせれば解ける <br>

* AGC019 B Reverse and Compare
    > アルファベットが登場する系(-> N進数系)の問題 <br>
    > こういうのは全探索O(N**2)，想定解O(N)の場合が多い <br>
    > 二分探索・尺取法など？<br>
    > N進数系は同じ値について接続を取り段々に積み上げる図を書くとわかりやすい <br>

* ABC165 Many Requiments
    > わからないので写した <br>
    > 広義単調増加数列なので全列挙が可能->10**10で諦めないで全列挙も候補に残しておく <br>
    > ## Combination全列挙方法
    > 1. 長さ1の数列(初期状態= {1})からi\>j => A_{i} \>= A_{j}を利用して，数列を順次生成する全部作ってO(nCk) <br>
    > 1. https://betrue12.hateblo.jp/entry/2020/05/02/233025
    > 1. https://note.com/nanigashi/n/n7cb379e2f3fd
    > 2. Pythonモジュール丸パクリ
    > ```python
    > from itertools import combinations_with_replacement as comb_rplc
    >   for seq in comb_rplc(range(1, 4), 2):
    >       print(seq)
    >
    >   (1, 1)
    >   (1, 2)
    >   (1, 3)
    >   (2, 2)
    >   (2, 3)
    >   (3, 3)
    > ```
    > 2. https://qiita.com/u2dayo/items/386142030a70d2db4e58

* ABC 039 D 画像処理
    > S->ImgSとする
    > 逆写像f^(-1)をGreedy searchで実装
    > S != Inv(ImgS)ならImpossible

* AGC 014 B Unplanned Queries
    > 接続辺をdirectに(u,v)で結んだ図を書いてみる <br>
    > どうやらすべての頂点についてrankが2nであることが必要十分ぽい <br>
    > GraphはTreeなのでDirectEdgesのうちいくらかを削除するが，削除する際にいい感じに回るから．<br>
    > 想定解法はLCAを使ってdist(u,v) = dist(r,u) + dist(r,v) - 2*dist(lc,u==v)になるからmod2でいい感じに処理できる <br>

* AGC 032 B Balanced Neighbors
    > 完全グラフからけずってゆく <br>
    > ### 教訓 構築系は
    > 1.    ゼロから追加
    > 2.    完全状態から削減

* CODEFESTIVAL 2017 Final C Time Gap
    > N~50と2**50に見えるがそうではない．<br>
    > 3回以上登場すれば答えはゼロ確定 <br>
    > 2回登場するときもd,24-dにバラして確定 <br>
    > 残った時刻について全探索しても2**12で余裕 <br>
    > ### time.max() - time.min()の差分を考えましょう!! e.g.: diff(22,0) = 2 <br>

* ARC 069 D Menagerie
    > 最初の2種類を決めたらあとは一意に定まる-> O(4) <br>
    > 演算規則を考えるのがめんどい <br>
    > 構成し終えたら全部チェックして合ってたらOK <br>

* ARC 097 D Equals
    > 典型的なgroupingの問題 <br>
    > 無向グラフを考えて，無向辺でつながっているgroup同士で数値の行き来は自由 <br>
    > 理想形({1,,,N})とグループごとでのsetを作りintersectで共通部分を取れば行ける <br>

* ABC 1-6 D AtCoder Express 2
    > N ~ 500で狭いのでN**2のi->jテーブルを作って<br>
    > (i,j) -> (x,y)の長方形に含まれる列車を数える，２次元累積和使えばO(1)でqueryを処理できる <br>
    > accum2Dのクラス作った，sum_squareも <br>

* ABC 152 E Flatten
    > Pythonなら脳死で通る <br>
    > ## LCM/GCDの計算方法 <br>
    > ### 数Xを素因数分解してmin(lp[i],rp[i]),max(lp[i],rp[i])をprime-wiseにかければgcd/lcmが出る <br>
    
* ABC 073 D joisino's travel
    > WarshallFloydで全点間最短経路->旅行する頂点を全部回す <br>
    > WarshallFloydのクラスをようやく作ったO(V**3) <br>
    > next_permutation(v.begin(),b.end())の使い方を覚えた do while <br>

* ABC 168 E Count Median
    > 最小値のMedianが取りうるMedianの下限 <br>
    > 最大値のMedianが取りうるMedianの上限は予想できる <br>
    > NがEvenかOddかで答えがだいたい２倍程度違う <br>
    > あとはindexを適当に調節するだけ <br>

* AGC 020 B Ice Rink Game
    > 各Roundのあとの生存人数をI[i]で管理する <br>
    > 計算量は各round O(1)で間に合う <br>
    > 下限は max(A[i],A[i]*ceil(I[i+1][0]/A[i])) <br>
    > 上限は A[i]*(floor(I[i+1][1] + 1)) <br>
    > I[i][0] > I[i][1]でアウトbreak  <br>
    > 面白い問題 <br>

* ABC 119 D Lazy Faith
    > STLのLower_boundで検索できる  <br>
    > 近くにある神社(up to 2)と寺(up to 2)を全探索 <br>

* AGC 039 B Graph Partition
    > むずすぎ３日悩んだ
    > dfsでunflodはunfoldの方向指定ができないので罪 <br>
    > 結果的に全点についてdfsして最大距離求める事になった <br>
    > 想定解はWarshall-Floydで全点間距離を求めてmax(dist[i][j])出だせる <br>
    > warshall-Floyd == 全点dfsのmax更新　の知見を得た <br>

* AGC 047 A Integer Product
    > めんどくさい　頭使う問題じゃない... <br>
    > ただの誤差論 double使うときはprecise converterと作る必要がある <br>
    > dotがある場合のconverterまでは実装した <br>

* AGC 031 B Reversi
    > 方針は昔から建てられていたが全然通らなかった <br>
    > 同じ数で分解してi番目のpositionにいる時点で最大何種類の塗り方が可能かdpする <br>
    > 勘違いしていたのはC_{i] < Sizeof Inputだと思ってたこと <br>
    > あとMOD取るのも最初忘れていた <br>
    > 実践だと通せないかも <br>

* ABC 059 C Sequence
    > 適当にやったら解けてしまった <br>
    > 初項を正にするか負にするかで2つ貪欲で調べて終わり <br>