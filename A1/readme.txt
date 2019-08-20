﻿Spencer Walls, 0734584
Assignment #1

Running the program:

Following compilation using the 'make' command in the terminal, the program may be run by entering './a1' at the command line. 

The user will be prompted to press 'Enter', which will then initiate a function that outputs all permutations of the characters 'c', 'a', 'r', 'b', 'o', and 'n', whereby each character appears precisely once in each permutation. 

Following this output, the user will be prompted to enter input for Ackermann's function, beginning with the input of parameter m, followed by parameter n. The solution to Ackermann's function with respect to the input data, i.e. A(m, n), will subsequently be printed. 

The user will then be prompted to input a number for which the square root will be computed via Newton's method and then printed. This function invokes a recursive implementation of the algorithm. Subsequently, the user will be prompted to input another number, of which the square root will again be computed, however this time by a non-recursive version of the algorithm. The resultant square root will once again be printed. 

If the user wishes to run the program a second time, simply enter './a1' at the command line again. 

Range limitations for Ackermann's function:

Following rigorous testing of Ackermann's function, it was determined that m may range from 0 to 3, and n may range from 0 to 12. Any input outside of these ranges yields a segmentation error. Thus, the maximum combination of parameters possible is A(3,12) which yields a result of 32765. It should be noted however that the default integer data type was selected; had the 'unsigned' integer data type been declared instead, the program would resultantly allow for integers of roughly twice this size. This approach might also be employed since Ackermann's function doesn't deal with negative numbers. 

Sample output:

Provided below is sample output generated by the program, including the inputs that were entered to produce the respective results:

***********************************

Press Enter to activate a function that outputs
every possible permutation of the string 'carbon'

 carbon
 carbno
 carobn
 carnbo
 caronb
 carnob
 cabron
 cabrno
 caorbn
 canrbo
 caornb
 canrob
 caborn
 cabnro
 caobrn
 canbro
 caonrb
 canorb
 cabonr
 cabnor
 caobnr
 canbor
 caonbr
 canobr
 crabon
 crabno
 craobn
 cranbo
 craonb
 cranob
 cbaron
 cbarno
 coarbn
 cnarbo
 coarnb
 cnarob
 cbaorn
 cbanro
 coabrn
 cnabro
 coanrb
 cnaorb
 cbaonr
 cbanor
 coabnr
 cnabor
 coanbr
 cnaobr
 crbaon
 crbano
 croabn
 crnabo
 croanb
 crnaob
 cbraon
 cbrano
 corabn
 cnrabo
 coranb
 cnraob
 cboarn
 cbnaro
 cobarn
 cnbaro
 conarb
 cnoarb
 cboanr
 cbnaor
 cobanr
 cnbaor
 conabr
 cnoabr
 crboan
 crbnao
 croban
 crnbao
 cronab
 crnoab
 cbroan
 cbrnao
 corban
 cnrbao
 cornab
 cnroab
 cboran
 cbnrao
 cobran
 cnbrao
 conrab
 cnorab
 cbonar
 cbnoar
 cobnar
 cnboar
 conbar
 cnobar
 crbona
 crbnoa
 crobna
 crnboa
 cronba
 crnoba
 cbrona
 cbrnoa
 corbna
 cnrboa
 cornba
 cnroba
 cborna
 cbnroa
 cobrna
 cnbroa
 conrba
 cnorba
 cbonra
 cbnora
 cobnra
 cnbora
 conbra
 cnobra
 acrbon
 acrbno
 acrobn
 acrnbo
 acronb
 acrnob
 acbron
 acbrno
 acorbn
 acnrbo
 acornb
 acnrob
 acborn
 acbnro
 acobrn
 acnbro
 aconrb
 acnorb
 acbonr
 acbnor
 acobnr
 acnbor
 aconbr
 acnobr
 rcabon
 rcabno
 rcaobn
 rcanbo
 rcaonb
 rcanob
 bcaron
 bcarno
 ocarbn
 ncarbo
 ocarnb
 ncarob
 bcaorn
 bcanro
 ocabrn
 ncabro
 ocanrb
 ncaorb
 bcaonr
 bcanor
 ocabnr
 ncabor
 ocanbr
 ncaobr
 rcbaon
 rcbano
 rcoabn
 rcnabo
 rcoanb
 rcnaob
 bcraon
 bcrano
 ocrabn
 ncrabo
 ocranb
 ncraob
 bcoarn
 bcnaro
 ocbarn
 ncbaro
 ocnarb
 ncoarb
 bcoanr
 bcnaor
 ocbanr
 ncbaor
 ocnabr
 ncoabr
 rcboan
 rcbnao
 rcoban
 rcnbao
 rconab
 rcnoab
 bcroan
 bcrnao
 ocrban
 ncrbao
 ocrnab
 ncroab
 bcoran
 bcnrao
 ocbran
 ncbrao
 ocnrab
 ncorab
 bconar
 bcnoar
 ocbnar
 ncboar
 ocnbar
 ncobar
 rcbona
 rcbnoa
 rcobna
 rcnboa
 rconba
 rcnoba
 bcrona
 bcrnoa
 ocrbna
 ncrboa
 ocrnba
 ncroba
 bcorna
 bcnroa
 ocbrna
 ncbroa
 ocnrba
 ncorba
 bconra
 bcnora
 ocbnra
 ncbora
 ocnbra
 ncobra
 arcbon
 arcbno
 arcobn
 arcnbo
 arconb
 arcnob
 abcron
 abcrno
 aocrbn
 ancrbo
 aocrnb
 ancrob
 abcorn
 abcnro
 aocbrn
 ancbro
 aocnrb
 ancorb
 abconr
 abcnor
 aocbnr
 ancbor
 aocnbr
 ancobr
 racbon
 racbno
 racobn
 racnbo
 raconb
 racnob
 bacron
 bacrno
 oacrbn
 nacrbo
 oacrnb
 nacrob
 bacorn
 bacnro
 oacbrn
 nacbro
 oacnrb
 nacorb
 baconr
 bacnor
 oacbnr
 nacbor
 oacnbr
 nacobr
 rbcaon
 rbcano
 rocabn
 rncabo
 rocanb
 rncaob
 brcaon
 brcano
 orcabn
 nrcabo
 orcanb
 nrcaob
 bocarn
 bncaro
 obcarn
 nbcaro
 oncarb
 nocarb
 bocanr
 bncaor
 obcanr
 nbcaor
 oncabr
 nocabr
 rbcoan
 rbcnao
 rocban
 rncbao
 rocnab
 rncoab
 brcoan
 brcnao
 orcban
 nrcbao
 orcnab
 nrcoab
 bocran
 bncrao
 obcran
 nbcrao
 oncrab
 nocrab
 bocnar
 bncoar
 obcnar
 nbcoar
 oncbar
 nocbar
 rbcona
 rbcnoa
 rocbna
 rncboa
 rocnba
 rncoba
 brcona
 brcnoa
 orcbna
 nrcboa
 orcnba
 nrcoba
 bocrna
 bncroa
 obcrna
 nbcroa
 oncrba
 nocrba
 bocnra
 bncora
 obcnra
 nbcora
 oncbra
 nocbra
 arbcon
 arbcno
 arocbn
 arncbo
 arocnb
 arncob
 abrcon
 abrcno
 aorcbn
 anrcbo
 aorcnb
 anrcob
 abocrn
 abncro
 aobcrn
 anbcro
 aoncrb
 anocrb
 abocnr
 abncor
 aobcnr
 anbcor
 aoncbr
 anocbr
 rabcon
 rabcno
 raocbn
 rancbo
 raocnb
 rancob
 barcon
 barcno
 oarcbn
 narcbo
 oarcnb
 narcob
 baocrn
 bancro
 oabcrn
 nabcro
 oancrb
 naocrb
 baocnr
 bancor
 oabcnr
 nabcor
 oancbr
 naocbr
 rbacon
 rbacno
 roacbn
 rnacbo
 roacnb
 rnacob
 bracon
 bracno
 oracbn
 nracbo
 oracnb
 nracob
 boacrn
 bnacro
 obacrn
 nbacro
 onacrb
 noacrb
 boacnr
 bnacor
 obacnr
 nbacor
 onacbr
 noacbr
 rbocan
 rbncao
 robcan
 rnbcao
 roncab
 rnocab
 brocan
 brncao
 orbcan
 nrbcao
 orncab
 nrocab
 borcan
 bnrcao
 obrcan
 nbrcao
 onrcab
 norcab
 boncar
 bnocar
 obncar
 nbocar
 onbcar
 nobcar
 rbocna
 rbncoa
 robcna
 rnbcoa
 roncba
 rnocba
 brocna
 brncoa
 orbcna
 nrbcoa
 orncba
 nrocba
 borcna
 bnrcoa
 obrcna
 nbrcoa
 onrcba
 norcba
 boncra
 bnocra
 obncra
 nbocra
 onbcra
 nobcra
 arbocn
 arbnco
 arobcn
 arnbco
 aroncb
 arnocb
 abrocn
 abrnco
 aorbcn
 anrbco
 aorncb
 anrocb
 aborcn
 abnrco
 aobrcn
 anbrco
 aonrcb
 anorcb
 aboncr
 abnocr
 aobncr
 anbocr
 aonbcr
 anobcr
 rabocn
 rabnco
 raobcn
 ranbco
 raoncb
 ranocb
 barocn
 barnco
 oarbcn
 narbco
 oarncb
 narocb
 baorcn
 banrco
 oabrcn
 nabrco
 oanrcb
 naorcb
 baoncr
 banocr
 oabncr
 nabocr
 oanbcr
 naobcr
 rbaocn
 rbanco
 roabcn
 rnabco
 roancb
 rnaocb
 braocn
 branco
 orabcn
 nrabco
 orancb
 nraocb
 boarcn
 bnarco
 obarcn
 nbarco
 onarcb
 noarcb
 boancr
 bnaocr
 obancr
 nbaocr
 onabcr
 noabcr
 rboacn
 rbnaco
 robacn
 rnbaco
 ronacb
 rnoacb
 broacn
 brnaco
 orbacn
 nrbaco
 ornacb
 nroacb
 boracn
 bnraco
 obracn
 nbraco
 onracb
 noracb
 bonacr
 bnoacr
 obnacr
 nboacr
 onbacr
 nobacr
 rbonca
 rbnoca
 robnca
 rnboca
 ronbca
 rnobca
 bronca
 brnoca
 orbnca
 nrboca
 ornbca
 nrobca
 bornca
 bnroca
 obrnca
 nbroca
 onrbca
 norbca
 bonrca
 bnorca
 obnrca
 nborca
 onbrca
 nobrca
 arbonc
 arbnoc
 arobnc
 arnboc
 aronbc
 arnobc
 abronc
 abrnoc
 aorbnc
 anrboc
 aornbc
 anrobc
 abornc
 abnroc
 aobrnc
 anbroc
 aonrbc
 anorbc
 abonrc
 abnorc
 aobnrc
 anborc
 aonbrc
 anobrc
 rabonc
 rabnoc
 raobnc
 ranboc
 raonbc
 ranobc
 baronc
 barnoc
 oarbnc
 narboc
 oarnbc
 narobc
 baornc
 banroc
 oabrnc
 nabroc
 oanrbc
 naorbc
 baonrc
 banorc
 oabnrc
 naborc
 oanbrc
 naobrc
 rbaonc
 rbanoc
 roabnc
 rnaboc
 roanbc
 rnaobc
 braonc
 branoc
 orabnc
 nraboc
 oranbc
 nraobc
 boarnc
 bnaroc
 obarnc
 nbaroc
 onarbc
 noarbc
 boanrc
 bnaorc
 obanrc
 nbaorc
 onabrc
 noabrc
 rboanc
 rbnaoc
 robanc
 rnbaoc
 ronabc
 rnoabc
 broanc
 brnaoc
 orbanc
 nrbaoc
 ornabc
 nroabc
 boranc
 bnraoc
 obranc
 nbraoc
 onrabc
 norabc
 bonarc
 bnoarc
 obnarc
 nboarc
 onbarc
 nobarc
 rbonac
 rbnoac
 robnac
 rnboac
 ronbac
 rnobac
 bronac
 brnoac
 orbnac
 nrboac
 ornbac
 nrobac
 bornac
 bnroac
 obrnac
 nbroac
 onrbac
 norbac
 bonrac
 bnorac
 obnrac
 nborac
 onbrac
 nobrac

Enter input for Ackermann's function,
whereby both m and n must be >= 0.
First, enter input for m: 1
Now, enter input for n: 2
A(1,2) = 4

Enter the number for which the square root
is to be computed by Newton's method (recursive): 1000
Enter the epsilon (accuracy) to be used for the calculation: 0.0001
The square root approximation = 31.622777

Enter the number for which the square root
is to be computed by Newton's method (non-recursive):  5000
Enter the epsilon (accuracy) to be used for the calculation: 0.00001
The square root approximation = 70.710678

To run this program again, please re-enter './a1'

***********************************