# one_commits__Samples__rock-paper-scissors_game

This is a sample so that I can commit this to the GitHub.

## 1. Question

項数Nの数列anが与えられる。この数列anの各項を階乗したbnを出力するプログラムを書け。  
ただし0!は1とする。  
inputs 1 の場合、以下の計算となる。

a_{n} = \{ 7, 2, 6, 5, 3 \}  
a_{n} = \{ 7!, 2!, 6!, 5!, 3! \}  
a_{n} = \{ 5040, 2, 720, 120, 6 \}  
↓  
b_{n} = \{ 5040, 2, 720, 120, 6 \}

## 2. Conditions

```
1≦N≦10
0≦a{i}≦6
```

## 3. Inputs and Outputs

### 3.1. Inputs

```
N
a{1} a{2} a{3} ... a{N}
```

一行目に項数Nが与えられ、
二行目以降は半角スペースを区切り文字として数列anが与えられる。

### 3.2. Outputs

```
b{1} b{2} b{3} ... b{N}
```

半角スペースを区切り文字としてb_{n}に相当する数列を出力する。

### 3.3. Examples

#### 3.3.1. Inputs 1

```
5
7 2 6 5 3
```
#### 3.3.2. Outputs 1

```
5040 2 720 120 6
```

※ Inputs 1 は input1.txt, Output 1 は output1.txt に記述されているとする。
