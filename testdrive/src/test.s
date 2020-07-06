.name "maxidef"
.comment "module de defense"

ld :buff,r1
goboucle0:	live %66
		zjmp %:finboucle0
		zjmp %:goboucle0
finboucle0:	xor r3,r3,r3

buff:	st r1,r1

