d = read.table("data")
C = d[2,1]
Cu = d[,1]
ti = 14
u = d[,3]

betai = 1.800
C1 = sum (Cu * exp(u * betai))
C2 = sum( Cu * (ti-u) * exp(u * betai))
C3 = sum( Cu * (ti-u) * u * betai * exp(u*betai))
C4 = ti * C1 - C2

fbeta = C * exp(ti * betai) / C1
fbetap = fbeta * C2 / C1
fbetapp = fbetap * C2 / C1 + fbeta * (C3*C1 - C2*C4)/C1/C1

c(fbeta, fbetap, fbetapp)
