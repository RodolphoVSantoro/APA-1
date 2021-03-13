def criaPontos(tmp, linhas, cor):
	for linha in linhas:
		xy = linha.split()
		p = Point(float(xy[0]), float(xy[1]))
		p.color = cor
		p.label_visible = False
		tmp.append(p)	

#inserir caminho completo
file = open("E:/Rodolpho/Documents/UFF/APA/caixaM1.txt", "r")
linhas = file.readlines()
file.close()
tmp = []
criaPontos(tmp, linhas, Color.RED)
$listaM1 =  List(*tmp)

tmp = []
file = open("E:/Rodolpho/Documents/UFF/APA/caixaM2.txt", "r")
linhas = file.readlines()
file.close()
criaPontos(tmp, linhas, Color.GREEN)
$listaM2 =  List(*tmp)

tmp = []
file = open("E:/Rodolpho/Documents/UFF/APA/caixaM3.txt", "r")
linhas = file.readlines()
file.close()
criaPontos(tmp, linhas, Color.BLUE)
$listaM3 =  List(*tmp)

tmp = []
file = open("E:/Rodolpho/Documents/UFF/APA/caixaM4.txt", "r")
linhas = file.readlines()
file.close()
criaPontos(tmp, linhas, Color.BLACK)
$listaM4 =  List(*tmp)

tmp = []
file = open("E:/Rodolpho/Documents/UFF/APA/caixa.txt", "r")
linhas = file.readlines()
file.close()
criaPontos(tmp, linhas, Color.YELLOW)
$listaM5 =  List(*tmp)

command("Fit(listaM1, {x, 1})")
command("Fit(listaM2, {x, 1})")
command("Fit(listaM3, {x, 1})")
command("Fit(listaM4, {x, 1})")
command("Fit(listaM5, {x, 1})")