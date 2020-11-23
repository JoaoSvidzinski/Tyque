//----------------------------------------------------------------------------------------// 
//GLOBAL VARIABLES AND MESSAGES
//----------------------------------------------------------------------------------------// 
inlets = 1;
outlets = 1;


var tapMsg = 'toMTap';
var GrainMsg = 'toGrain';
var toGrain2 = 'toGrain2';
var toRandom = 'toRandom';
var toGeneral = 'toGeneral';

//---------------------------------------------------------------------------------------//
// CLASS INSTANCES//
//----------------------------------------------------------------------------------------//
var Test, Gra1, Gra2, Gra3, Ob1, Ob2, Ob3;

//----------------------------------------------------------------------------------------// 
function displayAll() {
	outlet(0, tapMsg, 'displayAll');
	outlet(0, GrainMsg, 'displayAll');
}
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
//Harmoniser fonctions//
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
function setDuration(i, v) outlet(0, tapMsg, 'setDuration', i, v);
function setTransposition(i, v) outlet(0, tapMsg, 'setTransposition', i, v);
function setFd(i, v) outlet(0, tapMsg, 'setFd', i, v);
function setHStretch(i, v) outlet(0, tapMsg, 'sethStretch', i, v);
function outputAllFds(v) outlet(0, tapMsg, 'setFd', v);
function H_setInp(i, v) outlet(0, tapMsg, 'setInp', i, v); 
function H_setOut(i, v) outlet(0, tapMsg, 'setOut', i, v);
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
//Granular fonctions//
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
function setSize(i, v) outlet(0,GrainMsg, 'setSize', i, v);
function setDel(i, v)  outlet(0, GrainMsg, 'setDel', i, v);
function setRare(i, v) outlet(0, GrainMsg, 'setRare', i, v);
function setFdx(i, v) outlet(0, GrainMsg, 'setFdx', i, v);
function G_setInp(i, v) outlet(0, GrainMsg, 'setInp', i, v); 
function G_setOut(i, v) outlet(0, GrainMsg, 'setOut', i, v);
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
//Random functions//
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
function setCent(v) outlet(0, toRandom, 'cent', v);
function setGrain(v) outlet(0, toRandom, 'grain', v);
function setMetro(v) outlet(0, toRandom, 'gMetro', v);
function setMRar(Vmax) outlet(0, toRandom, 'rMax', Vmax);
function setMSwitch(V) outlet(0, toRandom, "rSwitch", V);

function setMSize(Vmin, Vmax) {
	outlet(0, toRandom, 'sMax', Vmax);
	outlet(0, toRandom, 'sMin', Vmin);
}
function setMDel(Vmin, Vmax) {
	outlet(0, toRandom, 'dMax', Vmax);
	outlet(0, toRandom, 'dMin', Vmin);
}
function setRmin(a, b, c, d, e, f, g) outlet(0, toRandom, "rMin", a, b, c, d, e, f, g);
function mode(V) outlet(0, toRandom, "mode", V);	
function RandMax(v) messnamed ("toRand2", "max", v);
function Random(a, b, c, d, e, f, g, h,i) {
	setCent(a); setGrain(b); setMetro(c); setMSize(d, e); setMDel(f, g); setMRar(h); setMSwitch(i);
} 
//----------------------------------------------------------------------------------------// 
//----------------------------------------------------------------------------------------// 
function updateMTapDisplays() {
	outputAllDurations();
	outputAllTranspositions();
	outputAllFds();
	outputAllHvds();
	outputAllInps();
	outputAllOuts();
}
//----------------------------------------------------------------------------------------// 
function setGlobalParameters(tStre, smooth, wH) {
	outlet(0, tapMsg, 'tStretch', tStre);
	outlet(0, tapMsg, 'smoothDuration', smooth);
	outlet(0, tapMsg, 'wHarmo', wH);
}
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
//General functions//
//----------------------------------------------------------------------------------------// 
//----------------------------------------------------------------------------------------// 
function setByHarmo(v) outlet(0, toGeneral, 'ByHarmo', v);
//----------------------------------------------------------------------------------------// 
//allReset function
//----------------------------------------------------------------------------------------// 
function allReset() {
	outlet(0, tapMsg, 'setDuration', 0);
	outlet(0, tapMsg, 'setFd',  0);
	outlet(0, tapMsg, 'setTransposition', 0);
	outlet(0, tapMsg, 'tStretch', 1);
	outlet(0, tapMsg, 'setInp',  1);
	outlet(0, tapMsg, 'setOut',  1);
	setGlobalParameters(0.4, 20, 0.5, 0.2);
	outlet(0, GrainMsg, 'setSize', 100);
	outlet(0, GrainMsg, 'setDel', 0);
	outlet(0, GrainMsg, 'setRare', 0.5);
	outlet(0, GrainMsg, 'setFdx', 0);
	outlet(0, GrainMsg, 'setInp', 1);
	outlet(0, GrainMsg, 'setOut', 1);
	Random(0, 0, 0, 0, 0, 0, 0, 0, 0);
	displayAll();
	
}
function G_setSize(a, b, c, d, e, f, g) {
	setSize(0, a); setSize(1, b); setSize(2, c); setSize(3, d); setSize(4, e); setSize(5, f); setSize(6, g); 
}
function G_setDel(a, b, c, d, e, f, g) {
	setDel(0, a); setDel(1, b); setDel(2, c); setDel(3, d); setDel(4, e); setDel(5, f); setDel(6, g); 
}
function G_setRare(a, b, c, d, e, f, g) {
	setRare(0, a); setRare(1, b); setRare(2, c); setRare(3, d); setRare(4, e); setRare(5, f); setRare(6, g); 
}
function H_setDuration(a, b, c, d, e, f, g) {
	setDuration(0, a); setDuration(1, b); setDuration(2, c); setDuration(3, d); setDuration(4, e); setDuration(5, f); setDuration(6, g); 
}
function H_setTransposition(a, b, c, d, e, f, g) {
	setTransposition(0, a); setTransposition(1, b); setTransposition(2, c); setTransposition(3, d); setTransposition(4, e); setTransposition(5, f); setTransposition(6, g); 
}
function H_setHStretch(a, b, c, d, e, f, g) {
	setHStretch(0, a); setHStretch(1, b); setHStretch(2, c); setHStretch(3, d); setHStretch(4, e); setHStretch(5, f); setHStretch(6, g); 
}
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
//echantillons functions//
//----------------------------------------------------------------------------------------// 
//----------------------------------------------------------------------------------------// 

function E1(a, b, c, d, e, f, g){
messnamed ("E1", "metro", a); messnamed ("E1", "lim", b); messnamed ("E1", "min", c);  messnamed ("E1", "max", d); 
messnamed ("E1", "env", e); 
}
function E2(a, b, c, d, e, f, g){
messnamed ("E2", "metro", a); messnamed ("E2", "lim", b); messnamed ("E2", "min", c);  messnamed ("E2", "max", d); 
messnamed ("E2", "env", e); 
}
function E3(a, b, c, d, e, f, g){
messnamed ("E3", "metro", a); messnamed ("E3", "lim", b); messnamed ("E3", "min", c);  messnamed ("E3", "max", d); 
messnamed ("E3", "env", e); messnamed ("E3s", "s", 1); 
}
function E3s(y, x) {
messnamed ("E3s", "s", 2);  messnamed ("E3s", "min", y);  messnamed ("E3s", "max", x); 
}
function Estop() {
	messnamed ("E1", "lim", 0); messnamed ("E2", "lim", 0); messnamed ("E3", "lim", 0);
}
//----------------------------------------------------------------------------------------//
//Matrix functions//
//----------------------------------------------------------------------------------------// 
function Amatrix (x) messnamed("toAmatrix", x);
function Imatrix (x) messnamed("toImatrix", x);
function Fmatrix (x) messnamed("toFmatrix", x);
function Gmatrix (x) messnamed("toGmatrix", x);
function Hmatrix (x) messnamed("toHmatrix", x);
//----------------------------------------------------------------------------------------//
//Grain functions//
//----------------------------------------------------------------------------------------//
function grain2 (x) messnamed("grain2", x);
//----------------------------------------------------------------------------------------// 
function On() {
	H_setInp(1); H_setOut(1); G_setInp(1); G_setOut(1); }
function setRamp(v) messnamed("ramp", v);
function by(t,x) {
	messnamed("Byramp", t); messnamed("ByV", x);
}
function trig(x) messnamed("Ttrig", x);
//----------------------------------------------------------------------------------------// 
/// E1(metro, lim, min, max, env) --------------------------------------------------------//
/// setGlobalParameters(tStretch, smoothDuration, wHarmo) --------------------------------//
//----------------------------------------------------------------------------------------// 
/// mode(v); RandMax(v)-------------------------------------------------------------------//
/// Random(cent, grain, gMetro, sMin, sMax, dMin, dMax, rMax, rSwitch)--------------------//
//----------------------------------------------------------------------------------------//
var classTest = function() {
	this.outlevel = 1;

	On();		
	Imatrix(1);
	Fmatrix(1);
	Gmatrix(1);
	Hmatrix(2);
	Amatrix(1);
	
	grain2(2);
	
	E1(100,100, 2000, 2000, 1);
	E2(0,100, 2000, 2000, 1);
	E3(0,100, 2000, 2000, 1);
	
	mode(1);
	RandMax(2400);
	Random(1, 1, 500, 30, 100, 1000, 5000, 0.8, 0);
	setRmin(0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5); 
	setGlobalParameters(1, 300, 50);	
	H_setDuration(200, 20000, 20000, 20000, 20000, 20000, 20000);
	//H_setTransposition(200, 200, 200, 200, 200, 200, 200);	
	H_setHStretch(1, 1, 1, 1, 1, 1, 1);
	setFd(0.5);


	//G_setSize(100, 200, 300, 400, 500, 600, 700);
	//G_setDel(1000, 2000, 3000, 4000, 5000, 3000, 2000);
	//G_setRare(1, 0.3, 0.5, 0.8, 0.9, 0.1, 1);
	setFdx(0.6);

	setByHarmo(0.3);
	setRamp(500);
	
	//messnamed("Grain2","gain", 1);
	//messnamed("Grain2","feed", 0.1);
	displayAll();
	}

	
var Primeiro = function() {

	On();		
	Imatrix(1);
	Fmatrix(1);
	Gmatrix(1);
	Hmatrix(2);
	Amatrix(1);
	
	grain2(2);
	
	by(50,1);
	E1(150,20, 2000, 2000, 6);
	E2(20,0, 1000, 2000, 4); //puis E2(20,10, 1000, 2000, 4)
	E3(30,0, 30, 40, 2);//puis E3(30,10, 30, 400, 4)
	
	mode(1);
	RandMax(2400);
	Random(1, 1, 500, 60, 100, 0000, 1000, 0.8, 0);
	setRmin(0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5); 
	
	setGlobalParameters(1, 300, 50);	
	H_setHStretch(1, 1, 1, 1, 1, 1, 1);
	setFdx(0.5); setFd(0.5);
	
	setByHarmo(0.3);
	setRamp(500);
	
	
	displayAll();
		
	post("__________Classe :", "Primeiro", "\n");

	}
var grave = function() {
	

	On();		
	Imatrix(2);
	Fmatrix(1);
	Gmatrix(5);
	Hmatrix(7);
	Amatrix(5); // puis messnamed("Amatrix", "clear");
	
	
	by(50, 0.2);
	E1(100,30, 5000, 10000, 7);
	E2(20,80, 1000, 2000, 7); 
	E3(30,40, 30, 400, 1);
	
	grain2(2);

	mode(3);
	Random(1, 1, 500, 70, 100, 0000, 1000, 0.8, 0);
	
	H_setDuration(0, 10, 250, 500, 600, 450, 200, 150);
	setHStretch(1);
	setGlobalParameters(1, 300, 50);
	setFdx(0.5); setFd(0.3);
	 
	setByHarmo(0.3);
	setRamp(3000);

	setRmin(0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5); 
	
	displayAll();
	post("__________Classe :", "grave", "\n");
	}
	
	var grave2 = function() {
	

	On();		
	Imatrix(1);
	Fmatrix(1);
	Gmatrix(1);
	Hmatrix(2);
	Amatrix(4); // puis messnamed("Amatrix", "clear");
	
	
	by(50, 0.2);
	E1(150,10, 5000, 10000, 7);
	E2(20,10, 5000, 10000, 7); 
	E3(30,5, 30, 40, 1);
	
	grain2(2);

	mode(1);
	Random(1, 0, 500, 70, 100, 0000, 1000, 0.8, 0);
	
	H_setDuration(0, 100, 25, 50, 60, 200, 500, 350);
	setHStretch(1);
	setGlobalParameters(1, 300, 50);
	setFdx(0.4); setFd(0.3);
	
	G_setSize(100, 200, 300, 400, 500, 600, 700);
	G_setDel(0, 0, 0, 0, 0, 0, 0);
	G_setRare(1, 0.3, 0.5, 0.8, 0.9, 0.1, 1);
		 
	setByHarmo(0.3);
	setRamp(3000);
	
	displayAll();
	post("__________Classe :", "grave", "\n");
	}
	
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
// DESCRIPTION OF SEQUENCES
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
function Test() {
	allReset();
	Test = new classTest();
	post("start", "\n");
	displayAll(); 	
	}

//----------------------------------------------------------------------------------------//
//SEQUENCE 0
//----------------------------------------------------------------------------------------//
function seq0() {
	
	allReset();
	post("open", "\n");
	
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 1
//----------------------------------------------------------------------------------------//

function seq1() {
	
	ob1 = new Primeiro();
	RandMax(100);

	displayAll(); 
	post("start", "\n");
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 2
//----------------------------------------------------------------------------------------//
function seq2() {
	
	by(10000,0.2);
	
	Imatrix(2);
	
	Amatrix(2);
	E1(150,20, 2000, 2000, 6);
	
	Random(1, 1, 300, 100, 200, 500, 1000, 0.8, 0);
	setRmin(0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6); 
	
	post("Sequencia 2", "\n");
}

function seq3() {
	
	Amatrix(1);
	E1(100,20, 1990, 2050, 6);
	
	Random(1, 1, 200, 80, 150, 500, 2000, 0.8, 0);
	setRmin(0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7); 
	
	post("Sequencia 3", "\n");
}

function seq4() {
	
	Imatrix(1);
	Amatrix(2);
	E1(100,30, 1990, 2050, 6);
	E2(20,10, 1000, 2000, 4);
	
	Random(1, 1, 100, 50, 100, 1000, 3000, 0.9, 0);
	setRmin(0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8); 
	
	by(4000, 0.4);
	
	post("Sequencia 4", "\n");
}

function seq5() {
	
	Amatrix(1);
	E1(100,30, 1900, 2000, 6);
	E3(30,10, 30, 400, 4);
	
	Random(1, 1, 50, 40, 80, 1000, 3000, 0.8, 0);
	
	post("Sequencia 5", "\n");
}

function seq6() {
	
	setRamp(1800);
	messnamed("Amatrix", "clear");
	by(1800, 0.8);
	
	E1(100, 30, 1800, 3000, 6);
	E2(20,20, 1000, 2000, 4);
		
	post("Sequencia 6", "\n");
}
function seq7() {
	
	Amatrix(1);
	RandMax(1000);
		
	Random(1, 1, 10, 30, 50, 5000, 5000, 1, 1);
	RandMax(24000);
	E1(100, 30, 1800, 5000, 6);
	E2(20, 80, 1000, 2000, 4);
	E3(30, 40, 30, 400, 4);	
	
	post("Sequencia 7", "\n");	
}

function seq8() { 
	post("Sequencia 8", "\n");

	Random(1, 1, 10, 30, 50, 1000, 5000, 1, 1);
	
	Imatrix(2);

	setRamp(1800);
	messnamed("Amatrix", "clear");
	E3(30, 40, 30, 400, 2);	

	H_setDuration(0, 200, 50, 0, 1000, 800, 300, 500);
	displayAll(); 	
}
function seq9() {
	post("Sequencia 09", "\n");
	E3(30, 89, 30, 400, 1);	
	
	Amatrix(3);
	H_setDuration(0, 100, 300, 500, 800, 1000, 2000, 3000);
	displayAll(); 	
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 10
//----------------------------------------------------------------------------------------//
function seq10() {
	post("Sequencia 10", "\n");
	
	E1(100, 10, 1800, 5000, 6);
	E2(20, 80, 1000, 3000, 4);
	Amatrix(4);
	
	setFdx(0.5); setFd(0.5);
	displayAll(); 	
}
function seq11() {
	post("Sequencia 11", "\n");
	E1(100, 5, 1800, 5000, 7);
	E2(20, 80, 1000, 3000, 5); 
	Amatrix(5);
	E3s(30, 400);
}
function seq12() {
	post("Sequencia 12", "\n");
	E1(100, 2, 1800, 5000, 7);
	Random(1, 1, 10, 50, 80, 3000, 10000, 0.6, 0);
	setRmin(0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5); 
	H_setDuration(0, 0, 1000, 500, 500, 50, 100, 300);
	E3s(50, 800);
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 13
//----------------------------------------------------------------------------------------//
function seq13() {
	post("Sequencia 13", "\n");
	
	ob2 = new Primeiro();
	Random(1, 1, 10, 50, 80, 3000, 10000, 0.8, 0);
	by(800, 0.9);
	
	grain2(1);
	Imatrix(5);

	displayAll(); 
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 14
//----------------------------------------------------------------------------------------//
function seq14() {
	post("Sequencia 14", "\n");
	
	Amatrix(2);
	setFdx(0.8); setFd(0.8);
	H_setDuration(0, 0, 500, 500, 800, 2500, 10, 300);
	by(5000, 0.95);
	displayAll(); 

}
//----------------------------------------------------------------------------------------//
//SEQUENCE 15
//----------------------------------------------------------------------------------------//
function seq15() {
	post("Sequencia 15", "\n");
	
	Amatrix(1);
	by(800, 0.4);
	
	E2(20,80, 1000, 3000, 2); 
	E3(30,40, 1990, 2200, 1);

	displayAll(); 
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 16
//----------------------------------------------------------------------------------------//
function seq16() {
	post("Sequencia 16", "\n");
	
	setRamp(1500);
	Amatrix(5);	
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 17
//----------------------------------------------------------------------------------------//
function seq17() {
	post("Sequencia 17", "\n");
	Amatrix(2);

}
function seq18() {
	post("Sequencia 18", "\n");
	
	Amatrix(1);

	H_setDuration(0, 10, 50, 500, 800, 600, 100, 200);
	setDel(5000);
	displayAll(); 
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 19
//----------------------------------------------------------------------------------------//
function seq19() {
	post("Sequencia 19", "\n");
	
	Gra1 = new grave();
	E3s(30, 400);
	
}
function seq20() {
	post("Sequencia 20", "\n");
	
	Amatrix(4);
	E3s(40, 1000);
	displayAll();
}
function seq21() {
	post("Sequencia 21", "\n");
	Gra2 = new grave2();
	
	E3s(30, 100);
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 22
//----------------------------------------------------------------------------------------//
function seq22() {
	post("Sequencia 22", "\n");
	
	E2(20,10, 5000, 10000, 6); 
	Random(1, 0, 500, 70, 100, 0000, 1000, 0.8, 1);

	H_setDuration(0, 100, 500, 0, 1000, 600, 800, 300);
	displayAll();
	E3s(30, 80);

}
function seq23() {
	post("Sequencia 23", "\n");
	E2(20,10, 5000, 10000, 5); 
	Amatrix(5);
	E3s(40, 100);

}
function seq24() {
	post("Sequencia 24", "\n");

	Imatrix(2);
	Amatrix(4);	
	E1(500, 1, 1800, 5000, 7);
	E2(20, 80, 1000, 2000, 6);
	E3(30, 40, 30, 400, 4);	

}
function seq25() {
	post("Sequencia 25", "\n");

	Amatrix(2);
	Imatrix(1);
	
	G_setSize(40, 80, 50, 100, 70, 60, 30);
	G_setDel(110, 330, 220, 440, 550, 330, 220);
	G_setRare(1, 0.4, 0.6, 0.7, 0.9, 0.1, 1);
	displayAll();
	
}
function seq26() {
	post("Sequencia 26", "\n");

	Amatrix(3);
	Imatrix(2);
	Random(1, 1, 1000, 30, 500, 0, 1000, 0.3, 0);
	setRmin(0.2, 0.1, 0.1, 0.1, 0.2, 0.2, 0.1); 

}
//----------------------------------------------------------------------------------------//
//SEQUENCE 27
//----------------------------------------------------------------------------------------//
function seq27() {
	post("Sequencia 27", "\n");
	
	E1(500, 1, 5000, 10000, 7);
	E2(500, 3, 9000, 10000, 4);
	E3(2, 95, 30, 2000, 2);	

}
function seq28() {
	post("Sequencia 28", "\n");

	Imatrix(2);
	Random(0, 1, 1000, 30, 500, 0, 1000, 0.2, 0);

 	H_setDuration(0, 10, 50, 500, 800, 600, 100, 200);
	H_setTransposition(-100, 1200, 210, 120, 2100, 1200, 90, 2100); 
	setFd(0.6);
	displayAll();
	
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 29
//----------------------------------------------------------------------------------------// 
function seq29() {
	post("Sequencia 29", "\n");

	Imatrix(1);
	H_setHStretch(1, 1, 1, 1, 1, 8, 9);
	displayAll();
}
function seq30() {
	post("Sequencia 30", "\n");

	Imatrix(2);
	displayAll();
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 31
//----------------------------------------------------------------------------------------//
function seq31() {
	post("Sequencia 31", "\n");
	post("pouco denso", "\n");
	
	setRamp(10000);
	Amatrix(5);

	Random(0, 1, 500, 30, 100, 500, 1000, 0.5, 0);
	setRmin(0.4, 0.3, 0.4, 0.3, 0.4, 0.3, 0.4); 

	E1(200, 2, 5000, 10000, 7);
	E2(200, 3, 9000, 10000, 4);
	E3(2, 90, 30, 500, 1);	
	
	displayAll();
}
function seq32() {
	post("Sequencia 32", "\n");

	Imatrix(2);
	Amatrix(3);
	
	E1(200, 1, 4000, 9000, 7);
	E2(200, 1, 9000, 9000, 6);
	E3(50, 50, 30, 500, 1);	
	

	displayAll();

}
//----------------------------------------------------------------------------------------//
//SEQUENCE 33
//----------------------------------------------------------------------------------------//
function seq33() {	
	post("Sequencia 33", "\n");
	
	
	Imatrix(5);
	Amatrix(1);
	
	E1(200, 5, 4000, 9000, 7);
	E2(200, 10, 9000, 9000, 6);
	E3(50, 50, 30, 500, 1);	
	
	Random(0, 1, 250, 30, 100, 500, 1000, 0.8, 0);
	setRmin(0.3, 0.2, 0.4, 08, 0.6, 0.7, 0.6); 
	
	displayAll();
}

function seq34() {
	
	Imatrix(5);
	Amatrix(2);
	
	post("Sequencia 34", "\n");
	E1(150, 10, 4000, 9000, 7);
	E2(150, 20, 9000, 9000, 6);
	E3(100, 50, 30, 500, 1);	

	Random(0, 1, 10, 30, 100, 500, 1000, 0.8, 0);
	setRmin(0.4, 0.6, 0.5, 0.7, 0.6, 0.4, 0.3); 

	displayAll();
}

function seq35() {
	post("Sequencia 35", "\n");


	ob1 = new Primeiro();
	RandMax(2000);
	
	E1(100,30, 1900, 2000, 6);
	E3(100, 10, 30, 400, 4);
	E2(100, 10, 1000, 2000, 4);
	
	Random(1, 1, 100, 50, 100, 1000, 3000, 0.8, 0);
	setRmin(0.6, 0.5, 0.6, 0.5, 0.6, 0.5, 0.6); 
	
	by(10000, 0.8);

	H_setDuration(0, 50, 0, 100, 0, 800, 2000, 500);

	displayAll(); 	
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 36
//----------------------------------------------------------------------------------------//
function seq36() {
	post("Sequencia 36", "\n");

	Amatrix(2);
	

	Random(1, 1, 10, 80, 100, 3000, 5000, 0.8, 1);
	H_setDuration(0, 500, 50, 80, 220, 1800, 0, 350);
	displayAll();
	
}
function seq37() {
	post("Sequencia 37", "\n");
	
	Amatrix(2);
	
	E1(100,30, 2000, 2000, 6);
	Random(1, 1, 10, 100, 200, 4000, 5000, 0.9, 1);
	displayAll();
}
function seq38() {
	post("Sequencia 38", "\n");
	
	Amatrix(1);
	
	E3(100, 10, 30, 400, 4);
	E2(100, 10, 1000, 2000, 4);
	
	H_setDuration(0, 0, 500, 80, 20, 900, 200, 30);
	Random(1, 1, 10, 100, 300, 5000, 7000, 0.8, 1);
	displayAll();
}
function seq39() {
	post("Sequencia 39", "\n");
	
	setRamp(300);
	Amatrix(5);
	
	E1(100,30, 1500, 2500, 7);
	Random(1, 1, 10, 200, 400, 7000, 8000, 0.7, 1);
	H_setDuration(0, 0, 500, 80, 20, 900, 200, 30);
	displayAll();
}
function seq40() {
	post("Sequencia 40", "\n");

	setFd(0.8); setFdx(0.8);
	H_setDuration(0, 1500, 70, 180, 240, 1000, 300, 10);
	displayAll();
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 41
//----------------------------------------------------------------------------------------//
function seq41() {
	post("Sequencia 41", "\n");

	Amatrix(3);
	Random(1, 1, 10, 30, 50, 5000, 5000, 1, 1);
	RandMax(24000);
	E1(100, 30, 1800, 5000, 6);
	E2(20, 80, 1000, 2000, 4);
	E3(30, 40, 30, 400, 4);	

	displayAll();
}
function seq42() {
	post("Sequencia 42", "\n");
	Obj1 = new Primeiro();

	Imatrix(5);
	E2(20, 80, 1000, 2000, 7);
	E3(30, 40, 30, 400, 2);	
	
	setFd(0.8); setFdx(0.8);
	displayAll();
}
function seq43() {
	post("Sequencia 42", "\n");

	grain2(1);
	Amatrix(2);

	displayAll();
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 44
//----------------------------------------------------------------------------------------//

function seq44() {
	post("Sequencia 44", "\n");

	Amatrix(1);
	RandMax(24000);
	E1(100, 30, 1800, 5000, 6);
	E2(20, 80, 1000, 2000, 4);
	E3(30, 40, 30, 400, 4);	
	
	Random(1, 1, 10, 50, 100, 8000, 10000, 1, 1);
}

function seq45() {
	post("Sequencia 45", "\n");
	
	Amatrix(2);
	H_setDuration(0, 3000, 70, 5000, 240, 6000, 300, 4500);
	Random(1, 1, 300, 80, 50, 8000, 10000, 0.8, 1);
	displayAll();
}

function seq46() {
	
	Amatrix(1);
	post("Sequencia 46", "\n");
	Random(1, 1, 200, 70, 50, 8000, 10000, 0.6, 1);
}

function seq47() {
	post("Sequencia 47", "\n");

	Amatrix(2);
	H_setDuration(0, 30, 7000, 50, 2400, 60, 3000, 450);

	Random(1, 1, 100, 80, 40, 9000, 10000, 0.9, 0);
	setRmin(0.8, 0.9, 0.8, 0.9, 0.8, 0.9, 0.8); 
	H_setDuration(0, 200, 3000, 5000, 240, 7000, 300, 7000);
	displayAll();
}

//----------------------------------------------------------------------------------------//
//SEQUENCE 48
//----------------------------------------------------------------------------------------//
function seq48() {
	post("Sequencia 48", "\n");

	Amatrix(1);
	E1(100, 50, 1800, 5000, 5);
	E2(20, 80, 1000, 2000, 4);
	E3(30, 40, 30, 400, 4);	
	grain2(1);
	H_setDuration(0, 2000, 300, 500, 24, 700, 3000, 70);
	displayAll();

}
function seq49() {
	post("Sequencia 49", "\n");

	Amatrix(2);
	E1(100, 70, 1800, 5000, 4);
	E2(20, 90, 1000, 2000, 4);
	E3(30, 80, 30, 400, 2);	
	H_setDuration(0, 20, 0, 5000, 240, 70, 300, 70000);
	displayAll();

}

function seq50() {
	post("Sequencia 50", "\n");
	
	Amatrix(1);
	E2(20, 90, 1000, 2000, 2);
	E3(30, 80, 30, 400, 1);	
	H_setDuration(0, 0, 0, 500, 2400, 2700, 300, 70);
	displayAll();
}

//----------------------------------------------------------------------------------------//
//SEQUENCE 51
//----------------------------------------------------------------------------------------//
function seq51() {
	post("Sequencia 51", "\n");

	setFd(0.99); setFdx(0.99);
	H_setDuration(0, 80, 100, 500, 240, 2700, 300, 700);
	displayAll();
}
function seq52() {
	
	by(1000, 0.01);
	Amatrix(5);
	//messnamed("Amatrix","clear");
	messnamed("Gmatrix","clear");
	messnamed("Hmatrix","clear");
	
	Imatrix(1);
	E1(150, 1, 1800, 5000, 5);
	E2(150, 1, 1000, 2000, 4);
	E3(150, 1, 30, 400, 4);	
	H_setDuration(0, 0, 100, 500, 240, 270, 30, 70);
	displayAll();

	post("Sequencia 52", "\n");
} 
function seq53() {
	
	messnamed("Amatrix","clear");
	by(1000, 0);
	
	E1(150, 0, 1800, 5000, 5);
	E2(150, 0, 1000, 2000, 4);
	E3(150, 0, 30, 400, 4);	

	messnamed("Grain2", "gain", 0);

	post("Sequencia 53", "\n");
} 
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
function anything()
{
	//does nothing
}

