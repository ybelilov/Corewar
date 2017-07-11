.name "zork"
.comment "I'M ALIIIIVE"

#l2:		sti r1, 9999999999, %:live
st r1, :live

live:	live %:l2

l2:		sti r1, 9999999999, %:live
