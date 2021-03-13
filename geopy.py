def criaPontos(tmp, linhas, cor):
	for linha in linhas:
		xy = linha.split()
		p = Point(float(xy[0]), float(xy[1]))
		p.color = cor
		p.label_visible = False
		tmp.append(p)	

#inserir caminho completo
file = open("E:/Rodolpho/Documents/UFF/APA/trabalho 1/bubble.txt", "r")
linhas = file.readlines()
file.close()
tmp = []
criaPontos(tmp, linhas, Color.RED)
$listaBubble =  List(*tmp)

tmp = []
file = open("E:/Rodolpho/Documents/UFF/APA/trabalho 1/heap.txt", "r")
linhas = file.readlines()
file.close()
criaPontos(tmp, linhas, Color.GREEN)
$listaHeap =  List(*tmp)

tmp = []
file = open("E:/Rodolpho/Documents/UFF/APA/trabalho 1/caixa.txt", "r")
linhas = file.readlines()
file.close()
criaPontos(tmp, linhas, Color.BLUE)
$listaCaixa =  List(*tmp)

command("Fit(listaBubble, {x^2, x})")
command("Fit(listaHeap, {x*log(x)})")
command("Fit(listaCaixa, {x, 1})")