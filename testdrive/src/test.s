.name           "name"
.comment        "comment"

and %6, %:test, r7
test: and %3, %7, r1
and %6, %:test, r7
and %6, %:test, r7
and %6, %:test, r7

# Line 4 - no label declared - PC Jump from 0 to 11 (2 + 4 + 4 + 1)

	#	and		=> 06 a4 					[2bytes instruction (1byte opcode && 1byte encoded byte)]
	#	%6		=> 00 00 00 00 06			[4bytes direct] 
	#	%:test	=> 00 00 00 0b				[4bytes direct label call]
	#	r7		=> 07						[1byte register]

# Line 5 => label test declared - PC Jump from 11 to 22 (2 + 4 + 4 + 1)

	#	and		=> 06 a4 					[2bytes instruction (1byte opcode && 1byte encoded byte)]
	# 	%3		=> 00 00 00 00 03			[4bytes direct]
	# 	%7		=> 00 00 00 00 07			[4bytes direct]
	# 	r1		=> 01						[1byte register]

# Line 6 => no label declared - PC Jump from 22 to 33 (2 + 4 + 4 + 1)
 
	#	and		=> 06 a4 					[2bytes instruction (1byte opcode && 1byte encoded byte)]
	# 	%6		=> 00 00 00 00 06			[4bytes direct]
	# 	%:test	=> ff ff ff ff f5			[4bytes direct]
	# 	r7		=> 07						[1byte register]
 
# Line 7 => no label declared - PC Jump from 33 to 44 (2 + 4 + 4 + 1)

	#	and		=> 06 a4 					[2bytes instruction (1byte opcode && 1byte encoded byte)]
	# 	%6		=> 00 00 00 00 06			[4bytes direct]
	# 	%:test	=> ff ff ff ff ea			[4bytes direct]
	# 	r7		=> 07						[1byte register]

# Line 8 => no label declared - PC Jump from 44 to 55 (2 + 4 + 4 + 1)

	#	and		=> 06 a4 					[2bytes instruction (1byte opcode && 1byte encoded byte)]
	# 	%6		=> 00 00 00 00 06			[4bytes direct]
	# 	%:test	=> ff ff ff ff df			[4bytes direct]
	# 	r7		=> 07						[1byte register]

0b = 11 	| 0 + 11

f5 = 245	| 255 - 11 
ea = 234	| 255 - 22
df = 223	| 255 - 33