/*
 * call_func.cpp
 *
 *  Created on: 2010-4-14
 *      Author: zzzzzzzzzzz
 *
 *      独立出来是因为这个函数不能做优化
 */

#pragma GCC push_options
#pragma GCC optimize ("O0")
unsigned long int call_func2__(void*func,bool ret,int argc,unsigned long *argv){
	unsigned long int ax_qi4;
	//以下是汇编密集地方，不能乱插语句
#ifdef ver_loongson_
	#define sp0 "512"
	__asm__ volatile (
	".set noreorder\n"
	"addiu	$sp,$sp,-" sp0 "\n"
	".set reorder\n");
	
	__asm__ volatile (
	".set noreorder\n"
	"lw $t0,%0\n"
	"lw $v0,%1\n"
	"li $v1,128\n"
	"beq $v0,$v1,case128\n"
	"li $v1,127\n"
	"beq $v0,$v1,case127\n"
	"li $v1,126\n"
	"beq $v0,$v1,case126\n"
	"li $v1,125\n"
	"beq $v0,$v1,case125\n"
	"li $v1,124\n"
	"beq $v0,$v1,case124\n"
	"li $v1,123\n"
	"beq $v0,$v1,case123\n"
	"li $v1,122\n"
	"beq $v0,$v1,case122\n"
	"li $v1,121\n"
	"beq $v0,$v1,case121\n"
	"li $v1,120\n"
	"beq $v0,$v1,case120\n"
	"li $v1,119\n"
	"beq $v0,$v1,case119\n"
	"li $v1,118\n"
	"beq $v0,$v1,case118\n"
	"li $v1,117\n"
	"beq $v0,$v1,case117\n"
	"li $v1,116\n"
	"beq $v0,$v1,case116\n"
	"li $v1,115\n"
	"beq $v0,$v1,case115\n"
	"li $v1,114\n"
	"beq $v0,$v1,case114\n"
	"li $v1,113\n"
	"beq $v0,$v1,case113\n"
	"li $v1,112\n"
	"beq $v0,$v1,case112\n"
	"li $v1,111\n"
	"beq $v0,$v1,case111\n"
	"li $v1,110\n"
	"beq $v0,$v1,case110\n"
	"li $v1,109\n"
	"beq $v0,$v1,case109\n"
	"li $v1,108\n"
	"beq $v0,$v1,case108\n"
	"li $v1,107\n"
	"beq $v0,$v1,case107\n"
	"li $v1,106\n"
	"beq $v0,$v1,case106\n"
	"li $v1,105\n"
	"beq $v0,$v1,case105\n"
	"li $v1,104\n"
	"beq $v0,$v1,case104\n"
	"li $v1,103\n"
	"beq $v0,$v1,case103\n"
	"li $v1,102\n"
	"beq $v0,$v1,case102\n"
	"li $v1,101\n"
	"beq $v0,$v1,case101\n"
	"li $v1,100\n"
	"beq $v0,$v1,case100\n"
	"li $v1,99\n"
	"beq $v0,$v1,case99\n"
	"li $v1,98\n"
	"beq $v0,$v1,case98\n"
	"li $v1,97\n"
	"beq $v0,$v1,case97\n"
	"li $v1,96\n"
	"beq $v0,$v1,case96\n"
	"li $v1,95\n"
	"beq $v0,$v1,case95\n"
	"li $v1,94\n"
	"beq $v0,$v1,case94\n"
	"li $v1,93\n"
	"beq $v0,$v1,case93\n"
	"li $v1,92\n"
	"beq $v0,$v1,case92\n"
	"li $v1,91\n"
	"beq $v0,$v1,case91\n"
	"li $v1,90\n"
	"beq $v0,$v1,case90\n"
	"li $v1,89\n"
	"beq $v0,$v1,case89\n"
	"li $v1,88\n"
	"beq $v0,$v1,case88\n"
	"li $v1,87\n"
	"beq $v0,$v1,case87\n"
	"li $v1,86\n"
	"beq $v0,$v1,case86\n"
	"li $v1,85\n"
	"beq $v0,$v1,case85\n"
	"li $v1,84\n"
	"beq $v0,$v1,case84\n"
	"li $v1,83\n"
	"beq $v0,$v1,case83\n"
	"li $v1,82\n"
	"beq $v0,$v1,case82\n"
	"li $v1,81\n"
	"beq $v0,$v1,case81\n"
	"li $v1,80\n"
	"beq $v0,$v1,case80\n"
	"li $v1,79\n"
	"beq $v0,$v1,case79\n"
	"li $v1,78\n"
	"beq $v0,$v1,case78\n"
	"li $v1,77\n"
	"beq $v0,$v1,case77\n"
	"li $v1,76\n"
	"beq $v0,$v1,case76\n"
	"li $v1,75\n"
	"beq $v0,$v1,case75\n"
	"li $v1,74\n"
	"beq $v0,$v1,case74\n"
	"li $v1,73\n"
	"beq $v0,$v1,case73\n"
	"li $v1,72\n"
	"beq $v0,$v1,case72\n"
	"li $v1,71\n"
	"beq $v0,$v1,case71\n"
	"li $v1,70\n"
	"beq $v0,$v1,case70\n"
	"li $v1,69\n"
	"beq $v0,$v1,case69\n"
	"li $v1,68\n"
	"beq $v0,$v1,case68\n"
	"li $v1,67\n"
	"beq $v0,$v1,case67\n"
	"li $v1,66\n"
	"beq $v0,$v1,case66\n"
	"li $v1,65\n"
	"beq $v0,$v1,case65\n"
	"li $v1,64\n"
	"beq $v0,$v1,case64\n"
	"li $v1,63\n"
	"beq $v0,$v1,case63\n"
	"li $v1,62\n"
	"beq $v0,$v1,case62\n"
	"li $v1,61\n"
	"beq $v0,$v1,case61\n"
	"li $v1,60\n"
	"beq $v0,$v1,case60\n"
	"li $v1,59\n"
	"beq $v0,$v1,case59\n"
	"li $v1,58\n"
	"beq $v0,$v1,case58\n"
	"li $v1,57\n"
	"beq $v0,$v1,case57\n"
	"li $v1,56\n"
	"beq $v0,$v1,case56\n"
	"li $v1,55\n"
	"beq $v0,$v1,case55\n"
	"li $v1,54\n"
	"beq $v0,$v1,case54\n"
	"li $v1,53\n"
	"beq $v0,$v1,case53\n"
	"li $v1,52\n"
	"beq $v0,$v1,case52\n"
	"li $v1,51\n"
	"beq $v0,$v1,case51\n"
	"li $v1,50\n"
	"beq $v0,$v1,case50\n"
	"li $v1,49\n"
	"beq $v0,$v1,case49\n"
	"li $v1,48\n"
	"beq $v0,$v1,case48\n"
	"li $v1,47\n"
	"beq $v0,$v1,case47\n"
	"li $v1,46\n"
	"beq $v0,$v1,case46\n"
	"li $v1,45\n"
	"beq $v0,$v1,case45\n"
	"li $v1,44\n"
	"beq $v0,$v1,case44\n"
	"li $v1,43\n"
	"beq $v0,$v1,case43\n"
	"li $v1,42\n"
	"beq $v0,$v1,case42\n"
	"li $v1,41\n"
	"beq $v0,$v1,case41\n"
	"li $v1,40\n"
	"beq $v0,$v1,case40\n"
	"li $v1,39\n"
	"beq $v0,$v1,case39\n"
	"li $v1,38\n"
	"beq $v0,$v1,case38\n"
	"li $v1,37\n"
	"beq $v0,$v1,case37\n"
	"li $v1,36\n"
	"beq $v0,$v1,case36\n"
	"li $v1,35\n"
	"beq $v0,$v1,case35\n"
	"li $v1,34\n"
	"beq $v0,$v1,case34\n"
	"li $v1,33\n"
	"beq $v0,$v1,case33\n"
	"li $v1,32\n"
	"beq $v0,$v1,case32\n"
	"li $v1,31\n"
	"beq $v0,$v1,case31\n"
	"li $v1,30\n"
	"beq $v0,$v1,case30\n"
	"li $v1,29\n"
	"beq $v0,$v1,case29\n"
	"li $v1,28\n"
	"beq $v0,$v1,case28\n"
	"li $v1,27\n"
	"beq $v0,$v1,case27\n"
	"li $v1,26\n"
	"beq $v0,$v1,case26\n"
	"li $v1,25\n"
	"beq $v0,$v1,case25\n"
	"li $v1,24\n"
	"beq $v0,$v1,case24\n"
	"li $v1,23\n"
	"beq $v0,$v1,case23\n"
	"li $v1,22\n"
	"beq $v0,$v1,case22\n"
	"li $v1,21\n"
	"beq $v0,$v1,case21\n"
	"li $v1,20\n"
	"beq $v0,$v1,case20\n"
	"li $v1,19\n"
	"beq $v0,$v1,case19\n"
	"li $v1,18\n"
	"beq $v0,$v1,case18\n"
	"li $v1,17\n"
	"beq $v0,$v1,case17\n"
	"li $v1,16\n"
	"beq $v0,$v1,case16\n"
	"li $v1,15\n"
	"beq $v0,$v1,case15\n"
	"li $v1,14\n"
	"beq $v0,$v1,case14\n"
	"li $v1,13\n"
	"beq $v0,$v1,case13\n"
	"li $v1,12\n"
	"beq $v0,$v1,case12\n"
	"li $v1,11\n"
	"beq $v0,$v1,case11\n"
	"li $v1,10\n"
	"beq $v0,$v1,case10\n"
	"li $v1,9\n"
	"beq $v0,$v1,case9\n"
	"li $v1,8\n"
	"beq $v0,$v1,case8\n"
	"li $v1,7\n"
	"beq $v0,$v1,case7\n"
	"li $v1,6\n"
	"beq $v0,$v1,case6\n"
	"li $v1,5\n"
	"beq $v0,$v1,case5\n"
	"li $v1,4\n"
	"beq $v0,$v1,case4\n"
	"li $v1,3\n"
	"beq $v0,$v1,case3\n"
	"li $v1,2\n"
	"beq $v0,$v1,case2\n"
	"li $v1,1\n"
	"beq $v0,$v1,case1\n"
	"li $v1,0\n"
	"beq $v0,$v1,case0\n"
	"case128:\n"
	"lw $t1,508($t0)\n"
	"sw $t1,508($sp)\n"
	"case127:\n"
	"lw $t1,504($t0)\n"
	"sw $t1,504($sp)\n"
	"case126:\n"
	"lw $t1,500($t0)\n"
	"sw $t1,500($sp)\n"
	"case125:\n"
	"lw $t1,496($t0)\n"
	"sw $t1,496($sp)\n"
	"case124:\n"
	"lw $t1,492($t0)\n"
	"sw $t1,492($sp)\n"
	"case123:\n"
	"lw $t1,488($t0)\n"
	"sw $t1,488($sp)\n"
	"case122:\n"
	"lw $t1,484($t0)\n"
	"sw $t1,484($sp)\n"
	"case121:\n"
	"lw $t1,480($t0)\n"
	"sw $t1,480($sp)\n"
	"case120:\n"
	"lw $t1,476($t0)\n"
	"sw $t1,476($sp)\n"
	"case119:\n"
	"lw $t1,472($t0)\n"
	"sw $t1,472($sp)\n"
	"case118:\n"
	"lw $t1,468($t0)\n"
	"sw $t1,468($sp)\n"
	"case117:\n"
	"lw $t1,464($t0)\n"
	"sw $t1,464($sp)\n"
	"case116:\n"
	"lw $t1,460($t0)\n"
	"sw $t1,460($sp)\n"
	"case115:\n"
	"lw $t1,456($t0)\n"
	"sw $t1,456($sp)\n"
	"case114:\n"
	"lw $t1,452($t0)\n"
	"sw $t1,452($sp)\n"
	"case113:\n"
	"lw $t1,448($t0)\n"
	"sw $t1,448($sp)\n"
	"case112:\n"
	"lw $t1,444($t0)\n"
	"sw $t1,444($sp)\n"
	"case111:\n"
	"lw $t1,440($t0)\n"
	"sw $t1,440($sp)\n"
	"case110:\n"
	"lw $t1,436($t0)\n"
	"sw $t1,436($sp)\n"
	"case109:\n"
	"lw $t1,432($t0)\n"
	"sw $t1,432($sp)\n"
	"case108:\n"
	"lw $t1,428($t0)\n"
	"sw $t1,428($sp)\n"
	"case107:\n"
	"lw $t1,424($t0)\n"
	"sw $t1,424($sp)\n"
	"case106:\n"
	"lw $t1,420($t0)\n"
	"sw $t1,420($sp)\n"
	"case105:\n"
	"lw $t1,416($t0)\n"
	"sw $t1,416($sp)\n"
	"case104:\n"
	"lw $t1,412($t0)\n"
	"sw $t1,412($sp)\n"
	"case103:\n"
	"lw $t1,408($t0)\n"
	"sw $t1,408($sp)\n"
	"case102:\n"
	"lw $t1,404($t0)\n"
	"sw $t1,404($sp)\n"
	"case101:\n"
	"lw $t1,400($t0)\n"
	"sw $t1,400($sp)\n"
	"case100:\n"
	"lw $t1,396($t0)\n"
	"sw $t1,396($sp)\n"
	"case99:\n"
	"lw $t1,392($t0)\n"
	"sw $t1,392($sp)\n"
	"case98:\n"
	"lw $t1,388($t0)\n"
	"sw $t1,388($sp)\n"
	"case97:\n"
	"lw $t1,384($t0)\n"
	"sw $t1,384($sp)\n"
	"case96:\n"
	"lw $t1,380($t0)\n"
	"sw $t1,380($sp)\n"
	"case95:\n"
	"lw $t1,376($t0)\n"
	"sw $t1,376($sp)\n"
	"case94:\n"
	"lw $t1,372($t0)\n"
	"sw $t1,372($sp)\n"
	"case93:\n"
	"lw $t1,368($t0)\n"
	"sw $t1,368($sp)\n"
	"case92:\n"
	"lw $t1,364($t0)\n"
	"sw $t1,364($sp)\n"
	"case91:\n"
	"lw $t1,360($t0)\n"
	"sw $t1,360($sp)\n"
	"case90:\n"
	"lw $t1,356($t0)\n"
	"sw $t1,356($sp)\n"
	"case89:\n"
	"lw $t1,352($t0)\n"
	"sw $t1,352($sp)\n"
	"case88:\n"
	"lw $t1,348($t0)\n"
	"sw $t1,348($sp)\n"
	"case87:\n"
	"lw $t1,344($t0)\n"
	"sw $t1,344($sp)\n"
	"case86:\n"
	"lw $t1,340($t0)\n"
	"sw $t1,340($sp)\n"
	"case85:\n"
	"lw $t1,336($t0)\n"
	"sw $t1,336($sp)\n"
	"case84:\n"
	"lw $t1,332($t0)\n"
	"sw $t1,332($sp)\n"
	"case83:\n"
	"lw $t1,328($t0)\n"
	"sw $t1,328($sp)\n"
	"case82:\n"
	"lw $t1,324($t0)\n"
	"sw $t1,324($sp)\n"
	"case81:\n"
	"lw $t1,320($t0)\n"
	"sw $t1,320($sp)\n"
	"case80:\n"
	"lw $t1,316($t0)\n"
	"sw $t1,316($sp)\n"
	"case79:\n"
	"lw $t1,312($t0)\n"
	"sw $t1,312($sp)\n"
	"case78:\n"
	"lw $t1,308($t0)\n"
	"sw $t1,308($sp)\n"
	"case77:\n"
	"lw $t1,304($t0)\n"
	"sw $t1,304($sp)\n"
	"case76:\n"
	"lw $t1,300($t0)\n"
	"sw $t1,300($sp)\n"
	"case75:\n"
	"lw $t1,296($t0)\n"
	"sw $t1,296($sp)\n"
	"case74:\n"
	"lw $t1,292($t0)\n"
	"sw $t1,292($sp)\n"
	"case73:\n"
	"lw $t1,288($t0)\n"
	"sw $t1,288($sp)\n"
	"case72:\n"
	"lw $t1,284($t0)\n"
	"sw $t1,284($sp)\n"
	"case71:\n"
	"lw $t1,280($t0)\n"
	"sw $t1,280($sp)\n"
	"case70:\n"
	"lw $t1,276($t0)\n"
	"sw $t1,276($sp)\n"
	"case69:\n"
	"lw $t1,272($t0)\n"
	"sw $t1,272($sp)\n"
	"case68:\n"
	"lw $t1,268($t0)\n"
	"sw $t1,268($sp)\n"
	"case67:\n"
	"lw $t1,264($t0)\n"
	"sw $t1,264($sp)\n"
	"case66:\n"
	"lw $t1,260($t0)\n"
	"sw $t1,260($sp)\n"
	"case65:\n"
	"lw $t1,256($t0)\n"
	"sw $t1,256($sp)\n"
	"case64:\n"
	"lw $t1,252($t0)\n"
	"sw $t1,252($sp)\n"
	"case63:\n"
	"lw $t1,248($t0)\n"
	"sw $t1,248($sp)\n"
	"case62:\n"
	"lw $t1,244($t0)\n"
	"sw $t1,244($sp)\n"
	"case61:\n"
	"lw $t1,240($t0)\n"
	"sw $t1,240($sp)\n"
	"case60:\n"
	"lw $t1,236($t0)\n"
	"sw $t1,236($sp)\n"
	"case59:\n"
	"lw $t1,232($t0)\n"
	"sw $t1,232($sp)\n"
	"case58:\n"
	"lw $t1,228($t0)\n"
	"sw $t1,228($sp)\n"
	"case57:\n"
	"lw $t1,224($t0)\n"
	"sw $t1,224($sp)\n"
	"case56:\n"
	"lw $t1,220($t0)\n"
	"sw $t1,220($sp)\n"
	"case55:\n"
	"lw $t1,216($t0)\n"
	"sw $t1,216($sp)\n"
	"case54:\n"
	"lw $t1,212($t0)\n"
	"sw $t1,212($sp)\n"
	"case53:\n"
	"lw $t1,208($t0)\n"
	"sw $t1,208($sp)\n"
	"case52:\n"
	"lw $t1,204($t0)\n"
	"sw $t1,204($sp)\n"
	"case51:\n"
	"lw $t1,200($t0)\n"
	"sw $t1,200($sp)\n"
	"case50:\n"
	"lw $t1,196($t0)\n"
	"sw $t1,196($sp)\n"
	"case49:\n"
	"lw $t1,192($t0)\n"
	"sw $t1,192($sp)\n"
	"case48:\n"
	"lw $t1,188($t0)\n"
	"sw $t1,188($sp)\n"
	"case47:\n"
	"lw $t1,184($t0)\n"
	"sw $t1,184($sp)\n"
	"case46:\n"
	"lw $t1,180($t0)\n"
	"sw $t1,180($sp)\n"
	"case45:\n"
	"lw $t1,176($t0)\n"
	"sw $t1,176($sp)\n"
	"case44:\n"
	"lw $t1,172($t0)\n"
	"sw $t1,172($sp)\n"
	"case43:\n"
	"lw $t1,168($t0)\n"
	"sw $t1,168($sp)\n"
	"case42:\n"
	"lw $t1,164($t0)\n"
	"sw $t1,164($sp)\n"
	"case41:\n"
	"lw $t1,160($t0)\n"
	"sw $t1,160($sp)\n"
	"case40:\n"
	"lw $t1,156($t0)\n"
	"sw $t1,156($sp)\n"
	"case39:\n"
	"lw $t1,152($t0)\n"
	"sw $t1,152($sp)\n"
	"case38:\n"
	"lw $t1,148($t0)\n"
	"sw $t1,148($sp)\n"
	"case37:\n"
	"lw $t1,144($t0)\n"
	"sw $t1,144($sp)\n"
	"case36:\n"
	"lw $t1,140($t0)\n"
	"sw $t1,140($sp)\n"
	"case35:\n"
	"lw $t1,136($t0)\n"
	"sw $t1,136($sp)\n"
	"case34:\n"
	"lw $t1,132($t0)\n"
	"sw $t1,132($sp)\n"
	"case33:\n"
	"lw $t1,128($t0)\n"
	"sw $t1,128($sp)\n"
	"case32:\n"
	"lw $t1,124($t0)\n"
	"sw $t1,124($sp)\n"
	"case31:\n"
	"lw $t1,120($t0)\n"
	"sw $t1,120($sp)\n"
	"case30:\n"
	"lw $t1,116($t0)\n"
	"sw $t1,116($sp)\n"
	"case29:\n"
	"lw $t1,112($t0)\n"
	"sw $t1,112($sp)\n"
	"case28:\n"
	"lw $t1,108($t0)\n"
	"sw $t1,108($sp)\n"
	"case27:\n"
	"lw $t1,104($t0)\n"
	"sw $t1,104($sp)\n"
	"case26:\n"
	"lw $t1,100($t0)\n"
	"sw $t1,100($sp)\n"
	"case25:\n"
	"lw $t1,96($t0)\n"
	"sw $t1,96($sp)\n"
	"case24:\n"
	"lw $t1,92($t0)\n"
	"sw $t1,92($sp)\n"
	"case23:\n"
	"lw $t1,88($t0)\n"
	"sw $t1,88($sp)\n"
	"case22:\n"
	"lw $t1,84($t0)\n"
	"sw $t1,84($sp)\n"
	"case21:\n"
	"lw $t1,80($t0)\n"
	"sw $t1,80($sp)\n"
	"case20:\n"
	"lw $t1,76($t0)\n"
	"sw $t1,76($sp)\n"
	"case19:\n"
	"lw $t1,72($t0)\n"
	"sw $t1,72($sp)\n"
	"case18:\n"
	"lw $t1,68($t0)\n"
	"sw $t1,68($sp)\n"
	"case17:\n"
	"lw $t1,64($t0)\n"
	"sw $t1,64($sp)\n"
	"case16:\n"
	"lw $t1,60($t0)\n"
	"sw $t1,60($sp)\n"
	"case15:\n"
	"lw $t1,56($t0)\n"
	"sw $t1,56($sp)\n"
	"case14:\n"
	"lw $t1,52($t0)\n"
	"sw $t1,52($sp)\n"
	"case13:\n"
	"lw $t1,48($t0)\n"
	"sw $t1,48($sp)\n"
	"case12:\n"
	"lw $t1,44($t0)\n"
	"sw $t1,44($sp)\n"
	"case11:\n"
	"lw $t1,40($t0)\n"
	"sw $t1,40($sp)\n"
	"case10:\n"
	"lw $t1,36($t0)\n"
	"sw $t1,36($sp)\n"
	"case9:\n"
	"lw $t1,32($t0)\n"
	"sw $t1,32($sp)\n"
	"case8:\n"
	"lw $t1,28($t0)\n"
	"sw $t1,28($sp)\n"
	"case7:\n"
	"lw $t1,24($t0)\n"
	"sw $t1,24($sp)\n"
	"case6:\n"
	"lw $t1,20($t0)\n"
	"sw $t1,20($sp)\n"
	"case5:\n"
	"lw $t1,16($t0)\n"
	"sw $t1,16($sp)\n"
	"case4:\n"
	"lw $a3,12($t0)\n"
	"case3:\n"
	"lw $a2,8($t0)\n"
	"case2:\n"
	"lw $a1,4($t0)\n"
	"case1:\n"
	"lw $a0,0($t0)\n"
	"case0:\n"
	".set reorder\n"	
	::"m"( argv ),"m"( argc ) );
	if(ret){
		__asm__ volatile (
		".set noreorder\n"
		"lw $v0,%1\n"
		"move $t9,$v0\n"
		"jalr $t9\n"
		"move	$at,$at\n"
		"sw	$v0,%0\n"
		".set reorder\n"
		:"=m"( ax_qi4 ):"m"( func ):"ra" );
	}else{
		__asm__ volatile (
		".set noreorder\n"
		"lw $v0,%0\n"
		"move $t9,$v0\n"
		"jalr $t9\n"
		"move	$at,$at\n"
		".set reorder\n"
		::"m"( func ):"ra" );
	}

	__asm__ volatile (
	".set noreorder\n"
	"addiu	$sp,$sp," sp0 "\n"
	".set reorder\n");
//#elifdef ver_64_
#elif defined( ver_64_ )
	unsigned long sp,sp0;
	__asm__ volatile ("mov %%rsp,%0":"=m"( sp0 ));
	sp=sp0;
	sp-=argc*8;
	__asm__ volatile (
			"push %%rbx\n"
			"mov %1,%%rbx\n"
			"mov %0,%%rax\n"
			"cmp $6,%%rax\n"
			"jbe be6\n"
			"sub $1024,%%rsp\n"
			"jmp be6n\n"
			"be6:\n"
			"sub $48,%%rsp\n"
			"be6n:\n"
			"cmp $0,%%rax\n"
			"jbe case0\n"
			"cmp $1,%%rax\n"
			"je case1\n"
			"cmp $2,%%rax\n"
			"je case2\n"
			"cmp $3,%%rax\n"
			"je case3\n"
			"cmp $4,%%rax\n"
			"je case4\n"
			"cmp $5,%%rax\n"
			"je case5\n"
			"cmp $6,%%rax\n"
			"je case6\n"
			"cmp $7,%%rax\n"
			"je case7\n"
			"cmp $8,%%rax\n"
			"je case8\n"
			"cmp $9,%%rax\n"
			"je case9\n"
			"cmp $10,%%rax\n"
			"je case10\n"
			"cmp $11,%%rax\n"
			"je case11\n"
			"cmp $12,%%rax\n"
			"je case12\n"
			"cmp $13,%%rax\n"
			"je case13\n"
			"cmp $14,%%rax\n"
			"je case14\n"
			"cmp $15,%%rax\n"
			"je case15\n"
			"cmp $16,%%rax\n"
			"je case16\n"
			"cmp $17,%%rax\n"
			"je case17\n"
			"cmp $18,%%rax\n"
			"je case18\n"
			"cmp $19,%%rax\n"
			"je case19\n"
			"cmp $20,%%rax\n"
			"je case20\n"
			"cmp $21,%%rax\n"
			"je case21\n"
			"cmp $22,%%rax\n"
			"je case22\n"
			"cmp $23,%%rax\n"
			"je case23\n"
			"cmp $24,%%rax\n"
			"je case24\n"
			"cmp $25,%%rax\n"
			"je case25\n"
			"cmp $26,%%rax\n"
			"je case26\n"
			"cmp $27,%%rax\n"
			"je case27\n"
			"cmp $28,%%rax\n"
			"je case28\n"
			"cmp $29,%%rax\n"
			"je case29\n"
			"cmp $30,%%rax\n"
			"je case30\n"
			"cmp $31,%%rax\n"
			"je case31\n"
			"cmp $32,%%rax\n"
			"je case32\n"
			"cmp $33,%%rax\n"
			"je case33\n"
			"cmp $34,%%rax\n"
			"je case34\n"
			"cmp $35,%%rax\n"
			"je case35\n"
			"cmp $36,%%rax\n"
			"je case36\n"
			"cmp $37,%%rax\n"
			"je case37\n"
			"cmp $38,%%rax\n"
			"je case38\n"
			"cmp $39,%%rax\n"
			"je case39\n"
			"cmp $40,%%rax\n"
			"je case40\n"
			"cmp $41,%%rax\n"
			"je case41\n"
			"cmp $42,%%rax\n"
			"je case42\n"
			"cmp $43,%%rax\n"
			"je case43\n"
			"cmp $44,%%rax\n"
			"je case44\n"
			"cmp $45,%%rax\n"
			"je case45\n"
			"cmp $46,%%rax\n"
			"je case46\n"
			"cmp $47,%%rax\n"
			"je case47\n"
			"cmp $48,%%rax\n"
			"je case48\n"
			"cmp $49,%%rax\n"
			"je case49\n"
			"cmp $50,%%rax\n"
			"je case50\n"
			"cmp $51,%%rax\n"
			"je case51\n"
			"cmp $52,%%rax\n"
			"je case52\n"
			"cmp $53,%%rax\n"
			"je case53\n"
			"cmp $54,%%rax\n"
			"je case54\n"
			"cmp $55,%%rax\n"
			"je case55\n"
			"cmp $56,%%rax\n"
			"je case56\n"
			"cmp $57,%%rax\n"
			"je case57\n"
			"cmp $58,%%rax\n"
			"je case58\n"
			"cmp $59,%%rax\n"
			"je case59\n"
			"cmp $60,%%rax\n"
			"je case60\n"
			"cmp $61,%%rax\n"
			"je case61\n"
			"cmp $62,%%rax\n"
			"je case62\n"
			"cmp $63,%%rax\n"
			"je case63\n"
			"cmp $64,%%rax\n"
			"je case64\n"
			"cmp $65,%%rax\n"
			"je case65\n"
			"cmp $66,%%rax\n"
			"je case66\n"
			"cmp $67,%%rax\n"
			"je case67\n"
			"cmp $68,%%rax\n"
			"je case68\n"
			"cmp $69,%%rax\n"
			"je case69\n"
			"cmp $70,%%rax\n"
			"je case70\n"
			"cmp $71,%%rax\n"
			"je case71\n"
			"cmp $72,%%rax\n"
			"je case72\n"
			"cmp $73,%%rax\n"
			"je case73\n"
			"cmp $74,%%rax\n"
			"je case74\n"
			"cmp $75,%%rax\n"
			"je case75\n"
			"cmp $76,%%rax\n"
			"je case76\n"
			"cmp $77,%%rax\n"
			"je case77\n"
			"cmp $78,%%rax\n"
			"je case78\n"
			"cmp $79,%%rax\n"
			"je case79\n"
			"cmp $80,%%rax\n"
			"je case80\n"
			"cmp $81,%%rax\n"
			"je case81\n"
			"cmp $82,%%rax\n"
			"je case82\n"
			"cmp $83,%%rax\n"
			"je case83\n"
			"cmp $84,%%rax\n"
			"je case84\n"
			"cmp $85,%%rax\n"
			"je case85\n"
			"cmp $86,%%rax\n"
			"je case86\n"
			"cmp $87,%%rax\n"
			"je case87\n"
			"cmp $88,%%rax\n"
			"je case88\n"
			"cmp $89,%%rax\n"
			"je case89\n"
			"cmp $90,%%rax\n"
			"je case90\n"
			"cmp $91,%%rax\n"
			"je case91\n"
			"cmp $92,%%rax\n"
			"je case92\n"
			"cmp $93,%%rax\n"
			"je case93\n"
			"cmp $94,%%rax\n"
			"je case94\n"
			"cmp $95,%%rax\n"
			"je case95\n"
			"cmp $96,%%rax\n"
			"je case96\n"
			"cmp $97,%%rax\n"
			"je case97\n"
			"cmp $98,%%rax\n"
			"je case98\n"
			"cmp $99,%%rax\n"
			"je case99\n"
			"cmp $100,%%rax\n"
			"je case100\n"
			"cmp $101,%%rax\n"
			"je case101\n"
			"cmp $102,%%rax\n"
			"je case102\n"
			"cmp $103,%%rax\n"
			"je case103\n"
			"cmp $104,%%rax\n"
			"je case104\n"
			"cmp $105,%%rax\n"
			"je case105\n"
			"cmp $106,%%rax\n"
			"je case106\n"
			"cmp $107,%%rax\n"
			"je case107\n"
			"cmp $108,%%rax\n"
			"je case108\n"
			"cmp $109,%%rax\n"
			"je case109\n"
			"cmp $110,%%rax\n"
			"je case110\n"
			"cmp $111,%%rax\n"
			"je case111\n"
			"cmp $112,%%rax\n"
			"je case112\n"
			"cmp $113,%%rax\n"
			"je case113\n"
			"cmp $114,%%rax\n"
			"je case114\n"
			"cmp $115,%%rax\n"
			"je case115\n"
			"cmp $116,%%rax\n"
			"je case116\n"
			"cmp $117,%%rax\n"
			"je case117\n"
			"cmp $118,%%rax\n"
			"je case118\n"
			"cmp $119,%%rax\n"
			"je case119\n"
			"cmp $120,%%rax\n"
			"je case120\n"
			"cmp $121,%%rax\n"
			"je case121\n"
			"cmp $122,%%rax\n"
			"je case122\n"
			"cmp $123,%%rax\n"
			"je case123\n"
			"cmp $124,%%rax\n"
			"je case124\n"
			"cmp $125,%%rax\n"
			"je case125\n"
			"cmp $126,%%rax\n"
			"je case126\n"
			"cmp $127,%%rax\n"
			"je case127\n"
			"case128:\n"
			"mov 1016(%%rbx),%%rax\n"
			"mov %%rax,976(%%rsp)\n"
			"case127:\n"
			"mov 1008(%%rbx),%%rax\n"
			"mov %%rax,968(%%rsp)\n"
			"case126:\n"
			"mov 1000(%%rbx),%%rax\n"
			"mov %%rax,960(%%rsp)\n"
			"case125:\n"
			"mov 992(%%rbx),%%rax\n"
			"mov %%rax,952(%%rsp)\n"
			"case124:\n"
			"mov 984(%%rbx),%%rax\n"
			"mov %%rax,944(%%rsp)\n"
			"case123:\n"
			"mov 976(%%rbx),%%rax\n"
			"mov %%rax,936(%%rsp)\n"
			"case122:\n"
			"mov 968(%%rbx),%%rax\n"
			"mov %%rax,928(%%rsp)\n"
			"case121:\n"
			"mov 960(%%rbx),%%rax\n"
			"mov %%rax,920(%%rsp)\n"
			"case120:\n"
			"mov 952(%%rbx),%%rax\n"
			"mov %%rax,912(%%rsp)\n"
			"case119:\n"
			"mov 944(%%rbx),%%rax\n"
			"mov %%rax,904(%%rsp)\n"
			"case118:\n"
			"mov 936(%%rbx),%%rax\n"
			"mov %%rax,896(%%rsp)\n"
			"case117:\n"
			"mov 928(%%rbx),%%rax\n"
			"mov %%rax,888(%%rsp)\n"
			"case116:\n"
			"mov 920(%%rbx),%%rax\n"
			"mov %%rax,880(%%rsp)\n"
			"case115:\n"
			"mov 912(%%rbx),%%rax\n"
			"mov %%rax,872(%%rsp)\n"
			"case114:\n"
			"mov 904(%%rbx),%%rax\n"
			"mov %%rax,864(%%rsp)\n"
			"case113:\n"
			"mov 896(%%rbx),%%rax\n"
			"mov %%rax,856(%%rsp)\n"
			"case112:\n"
			"mov 888(%%rbx),%%rax\n"
			"mov %%rax,848(%%rsp)\n"
			"case111:\n"
			"mov 880(%%rbx),%%rax\n"
			"mov %%rax,840(%%rsp)\n"
			"case110:\n"
			"mov 872(%%rbx),%%rax\n"
			"mov %%rax,832(%%rsp)\n"
			"case109:\n"
			"mov 864(%%rbx),%%rax\n"
			"mov %%rax,824(%%rsp)\n"
			"case108:\n"
			"mov 856(%%rbx),%%rax\n"
			"mov %%rax,816(%%rsp)\n"
			"case107:\n"
			"mov 848(%%rbx),%%rax\n"
			"mov %%rax,808(%%rsp)\n"
			"case106:\n"
			"mov 840(%%rbx),%%rax\n"
			"mov %%rax,800(%%rsp)\n"
			"case105:\n"
			"mov 832(%%rbx),%%rax\n"
			"mov %%rax,792(%%rsp)\n"
			"case104:\n"
			"mov 824(%%rbx),%%rax\n"
			"mov %%rax,784(%%rsp)\n"
			"case103:\n"
			"mov 816(%%rbx),%%rax\n"
			"mov %%rax,776(%%rsp)\n"
			"case102:\n"
			"mov 808(%%rbx),%%rax\n"
			"mov %%rax,768(%%rsp)\n"
			"case101:\n"
			"mov 800(%%rbx),%%rax\n"
			"mov %%rax,760(%%rsp)\n"
			"case100:\n"
			"mov 792(%%rbx),%%rax\n"
			"mov %%rax,752(%%rsp)\n"
			"case99:\n"
			"mov 784(%%rbx),%%rax\n"
			"mov %%rax,744(%%rsp)\n"
			"case98:\n"
			"mov 776(%%rbx),%%rax\n"
			"mov %%rax,736(%%rsp)\n"
			"case97:\n"
			"mov 768(%%rbx),%%rax\n"
			"mov %%rax,728(%%rsp)\n"
			"case96:\n"
			"mov 760(%%rbx),%%rax\n"
			"mov %%rax,720(%%rsp)\n"
			"case95:\n"
			"mov 752(%%rbx),%%rax\n"
			"mov %%rax,712(%%rsp)\n"
			"case94:\n"
			"mov 744(%%rbx),%%rax\n"
			"mov %%rax,704(%%rsp)\n"
			"case93:\n"
			"mov 736(%%rbx),%%rax\n"
			"mov %%rax,696(%%rsp)\n"
			"case92:\n"
			"mov 728(%%rbx),%%rax\n"
			"mov %%rax,688(%%rsp)\n"
			"case91:\n"
			"mov 720(%%rbx),%%rax\n"
			"mov %%rax,680(%%rsp)\n"
			"case90:\n"
			"mov 712(%%rbx),%%rax\n"
			"mov %%rax,672(%%rsp)\n"
			"case89:\n"
			"mov 704(%%rbx),%%rax\n"
			"mov %%rax,664(%%rsp)\n"
			"case88:\n"
			"mov 696(%%rbx),%%rax\n"
			"mov %%rax,656(%%rsp)\n"
			"case87:\n"
			"mov 688(%%rbx),%%rax\n"
			"mov %%rax,648(%%rsp)\n"
			"case86:\n"
			"mov 680(%%rbx),%%rax\n"
			"mov %%rax,640(%%rsp)\n"
			"case85:\n"
			"mov 672(%%rbx),%%rax\n"
			"mov %%rax,632(%%rsp)\n"
			"case84:\n"
			"mov 664(%%rbx),%%rax\n"
			"mov %%rax,624(%%rsp)\n"
			"case83:\n"
			"mov 656(%%rbx),%%rax\n"
			"mov %%rax,616(%%rsp)\n"
			"case82:\n"
			"mov 648(%%rbx),%%rax\n"
			"mov %%rax,608(%%rsp)\n"
			"case81:\n"
			"mov 640(%%rbx),%%rax\n"
			"mov %%rax,600(%%rsp)\n"
			"case80:\n"
			"mov 632(%%rbx),%%rax\n"
			"mov %%rax,592(%%rsp)\n"
			"case79:\n"
			"mov 624(%%rbx),%%rax\n"
			"mov %%rax,584(%%rsp)\n"
			"case78:\n"
			"mov 616(%%rbx),%%rax\n"
			"mov %%rax,576(%%rsp)\n"
			"case77:\n"
			"mov 608(%%rbx),%%rax\n"
			"mov %%rax,568(%%rsp)\n"
			"case76:\n"
			"mov 600(%%rbx),%%rax\n"
			"mov %%rax,560(%%rsp)\n"
			"case75:\n"
			"mov 592(%%rbx),%%rax\n"
			"mov %%rax,552(%%rsp)\n"
			"case74:\n"
			"mov 584(%%rbx),%%rax\n"
			"mov %%rax,544(%%rsp)\n"
			"case73:\n"
			"mov 576(%%rbx),%%rax\n"
			"mov %%rax,536(%%rsp)\n"
			"case72:\n"
			"mov 568(%%rbx),%%rax\n"
			"mov %%rax,528(%%rsp)\n"
			"case71:\n"
			"mov 560(%%rbx),%%rax\n"
			"mov %%rax,520(%%rsp)\n"
			"case70:\n"
			"mov 552(%%rbx),%%rax\n"
			"mov %%rax,512(%%rsp)\n"
			"case69:\n"
			"mov 544(%%rbx),%%rax\n"
			"mov %%rax,504(%%rsp)\n"
			"case68:\n"
			"mov 536(%%rbx),%%rax\n"
			"mov %%rax,496(%%rsp)\n"
			"case67:\n"
			"mov 528(%%rbx),%%rax\n"
			"mov %%rax,488(%%rsp)\n"
			"case66:\n"
			"mov 520(%%rbx),%%rax\n"
			"mov %%rax,480(%%rsp)\n"
			"case65:\n"
			"mov 512(%%rbx),%%rax\n"
			"mov %%rax,472(%%rsp)\n"
			"case64:\n"
			"mov 504(%%rbx),%%rax\n"
			"mov %%rax,464(%%rsp)\n"
			"case63:\n"
			"mov 496(%%rbx),%%rax\n"
			"mov %%rax,456(%%rsp)\n"
			"case62:\n"
			"mov 488(%%rbx),%%rax\n"
			"mov %%rax,448(%%rsp)\n"
			"case61:\n"
			"mov 480(%%rbx),%%rax\n"
			"mov %%rax,440(%%rsp)\n"
			"case60:\n"
			"mov 472(%%rbx),%%rax\n"
			"mov %%rax,432(%%rsp)\n"
			"case59:\n"
			"mov 464(%%rbx),%%rax\n"
			"mov %%rax,424(%%rsp)\n"
			"case58:\n"
			"mov 456(%%rbx),%%rax\n"
			"mov %%rax,416(%%rsp)\n"
			"case57:\n"
			"mov 448(%%rbx),%%rax\n"
			"mov %%rax,408(%%rsp)\n"
			"case56:\n"
			"mov 440(%%rbx),%%rax\n"
			"mov %%rax,400(%%rsp)\n"
			"case55:\n"
			"mov 432(%%rbx),%%rax\n"
			"mov %%rax,392(%%rsp)\n"
			"case54:\n"
			"mov 424(%%rbx),%%rax\n"
			"mov %%rax,384(%%rsp)\n"
			"case53:\n"
			"mov 416(%%rbx),%%rax\n"
			"mov %%rax,376(%%rsp)\n"
			"case52:\n"
			"mov 408(%%rbx),%%rax\n"
			"mov %%rax,368(%%rsp)\n"
			"case51:\n"
			"mov 400(%%rbx),%%rax\n"
			"mov %%rax,360(%%rsp)\n"
			"case50:\n"
			"mov 392(%%rbx),%%rax\n"
			"mov %%rax,352(%%rsp)\n"
			"case49:\n"
			"mov 384(%%rbx),%%rax\n"
			"mov %%rax,344(%%rsp)\n"
			"case48:\n"
			"mov 376(%%rbx),%%rax\n"
			"mov %%rax,336(%%rsp)\n"
			"case47:\n"
			"mov 368(%%rbx),%%rax\n"
			"mov %%rax,328(%%rsp)\n"
			"case46:\n"
			"mov 360(%%rbx),%%rax\n"
			"mov %%rax,320(%%rsp)\n"
			"case45:\n"
			"mov 352(%%rbx),%%rax\n"
			"mov %%rax,312(%%rsp)\n"
			"case44:\n"
			"mov 344(%%rbx),%%rax\n"
			"mov %%rax,304(%%rsp)\n"
			"case43:\n"
			"mov 336(%%rbx),%%rax\n"
			"mov %%rax,296(%%rsp)\n"
			"case42:\n"
			"mov 328(%%rbx),%%rax\n"
			"mov %%rax,288(%%rsp)\n"
			"case41:\n"
			"mov 320(%%rbx),%%rax\n"
			"mov %%rax,280(%%rsp)\n"
			"case40:\n"
			"mov 312(%%rbx),%%rax\n"
			"mov %%rax,272(%%rsp)\n"
			"case39:\n"
			"mov 304(%%rbx),%%rax\n"
			"mov %%rax,264(%%rsp)\n"
			"case38:\n"
			"mov 296(%%rbx),%%rax\n"
			"mov %%rax,256(%%rsp)\n"
			"case37:\n"
			"mov 288(%%rbx),%%rax\n"
			"mov %%rax,248(%%rsp)\n"
			"case36:\n"
			"mov 280(%%rbx),%%rax\n"
			"mov %%rax,240(%%rsp)\n"
			"case35:\n"
			"mov 272(%%rbx),%%rax\n"
			"mov %%rax,232(%%rsp)\n"
			"case34:\n"
			"mov 264(%%rbx),%%rax\n"
			"mov %%rax,224(%%rsp)\n"
			"case33:\n"
			"mov 256(%%rbx),%%rax\n"
			"mov %%rax,216(%%rsp)\n"
			"case32:\n"
			"mov 248(%%rbx),%%rax\n"
			"mov %%rax,208(%%rsp)\n"
			"case31:\n"
			"mov 240(%%rbx),%%rax\n"
			"mov %%rax,200(%%rsp)\n"
			"case30:\n"
			"mov 232(%%rbx),%%rax\n"
			"mov %%rax,192(%%rsp)\n"
			"case29:\n"
			"mov 224(%%rbx),%%rax\n"
			"mov %%rax,184(%%rsp)\n"
			"case28:\n"
			"mov 216(%%rbx),%%rax\n"
			"mov %%rax,176(%%rsp)\n"
			"case27:\n"
			"mov 208(%%rbx),%%rax\n"
			"mov %%rax,168(%%rsp)\n"
			"case26:\n"
			"mov 200(%%rbx),%%rax\n"
			"mov %%rax,160(%%rsp)\n"
			"case25:\n"
			"mov 192(%%rbx),%%rax\n"
			"mov %%rax,152(%%rsp)\n"
			"case24:\n"
			"mov 184(%%rbx),%%rax\n"
			"mov %%rax,144(%%rsp)\n"
			"case23:\n"
			"mov 176(%%rbx),%%rax\n"
			"mov %%rax,136(%%rsp)\n"
			"case22:\n"
			"mov 168(%%rbx),%%rax\n"
			"mov %%rax,128(%%rsp)\n"
			"case21:\n"
			"mov 160(%%rbx),%%rax\n"
			"mov %%rax,120(%%rsp)\n"
			"case20:\n"
			"mov 152(%%rbx),%%rax\n"
			"mov %%rax,112(%%rsp)\n"
			"case19:\n"
			"mov 144(%%rbx),%%rax\n"
			"mov %%rax,104(%%rsp)\n"
			"case18:\n"
			"mov 136(%%rbx),%%rax\n"
			"mov %%rax,96(%%rsp)\n"
			"case17:\n"
			"mov 128(%%rbx),%%rax\n"
			"mov %%rax,88(%%rsp)\n"
			"case16:\n"
			"mov 120(%%rbx),%%rax\n"
			"mov %%rax,80(%%rsp)\n"
			"case15:\n"
			"mov 112(%%rbx),%%rax\n"
			"mov %%rax,72(%%rsp)\n"
			"case14:\n"
			"mov 104(%%rbx),%%rax\n"
			"mov %%rax,64(%%rsp)\n"
			"case13:\n"
			"mov 96(%%rbx),%%rax\n"
			"mov %%rax,56(%%rsp)\n"
			"case12:\n"
			"mov 88(%%rbx),%%rax\n"
			"mov %%rax,48(%%rsp)\n"
			"case11:\n"
			"mov 80(%%rbx),%%rax\n"
			"mov %%rax,40(%%rsp)\n"
			"case10:\n"
			"mov 72(%%rbx),%%rax\n"
			"mov %%rax,32(%%rsp)\n"
			"case9:\n"
			"mov 64(%%rbx),%%rax\n"
			"mov %%rax,24(%%rsp)\n"
			"case8:\n"
			"mov 56(%%rbx),%%rax\n"
			"mov %%rax,16(%%rsp)\n"
			"case7:\n"
			"mov 48(%%rbx),%%rax\n"
			"mov %%rax,8(%%rsp)\n"
			"mov 40(%%rbx),%%rax\n"
			"mov %%rax,0(%%rsp)\n"
			"case6:\n"
			"mov 40(%%rbx),%%r9\n"
			"case5:\n"
			"mov 32(%%rbx),%%r8\n"
			"case4:\n"
			"mov 24(%%rbx),%%rcx\n"
			"case3:\n"
			"mov 16(%%rbx),%%rdx\n"
			"case2:\n"
			"mov 8(%%rbx),%%rsi\n"
			"case1:\n"
			"mov 0(%%rbx),%%rdi\n"
			"case0:\n"
			"pop %%rbx\n"
			"mov $0x0,%%eax\n"
			::"m"( argc ),"m"( argv ),"m"( sp ));
	if(ret){
		__asm__ volatile (
				"callq *%1" "\n"
				"mov %%rax,%0" "\n"
				"mov %2,%%rsp\n"
				:"=m"( ax_qi4  ):"m"( func ),"m"( sp0 ));
	}else{
		__asm__ volatile (
				"callq *%0" "\n"
				"mov %1,%%rsp\n"
				::"m"( func ),"m"( sp0 ));
	}
#else
	int i;
	unsigned long sp,sp0;
	__asm__ volatile ("mov %%esp,%0":"=m"( sp0 ));
	sp=sp0;
	for(i=argc-1;i>=0;i--,sp-=4)
		__asm__ volatile ("mov %0,%%esp\n\tmov %1,%%eax\n\tmov %%eax,(%%esp)"
				::"m"( sp ),"m"( argv[i] ) );
	__asm__ volatile ("call *%1\n\tmov %%eax,%0\n\tmov %2,%%esp"
			:"=m"( ax_qi4  ):"m"( func ),"m"( sp0 ));
#endif
	//以上是汇编密集地方，不能乱插语句
	return ax_qi4;
}
#pragma GCC pop_options
