# Corewar
 ### Translator

The translatlor ill be an easy part.
We will have two parts : 
- Header
- instructions

 #### Header : 
- translate_magic_nb() : write the magic number in binary in the file
- translate_name() : write name in binary
- write_padding() : will be used twice, write 4 bytes of zeroes in binary
- translate_instructions_size() : total size of instruction will be saved in data after parsing state.
- translate_comment() : will be close to translate_name(), it will transate thr comment
- padding again, same used before

 #### instructions : 

The translation of instruction is more intereseting, as we can't know what will come in what order.
I would suggest doing fnction pointer array whith the following states that will be adopted depending on current token : 

- instruction
- encoding bytes
- reg
- dir
- ind
- label_call
