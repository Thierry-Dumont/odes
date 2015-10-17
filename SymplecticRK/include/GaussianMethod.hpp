#ifndef GaussianMethod__h
#define GaussianMethod__h
#include <cmath>
#include <iostream>
#include "GenericException.hpp"
//#define DEBUG
namespace SymplectikRK{
  ///////////////////////////////////////////////////////////////////////////
  /// Build coefficients for symplectic gaussian RK.
  /// \brief  Build coefficients for symplectic gaussian RK.
  ///////////////////////////////////////////////////////////////////////////
  template<int nsteps,class Double> class GaussianMethod
  {
    // default template, never instanciated.
  };
  // Classical "double" precision. 
  template<int nsteps> class GaussianMethod<nsteps,double>
  {
  protected:
    double a[nsteps*nsteps];
    double b[nsteps],d[nsteps];
  
    //! constructor.
    GaussianMethod()
    {
      init();
    }
    //! multiply coefficients by h.
    //! \param h
    void change_h(double h)
    {
      init();
      for(int i=0;i<nsteps*nsteps;i++)
	a[i]*=h;
      for(int i=0;i<nsteps;i++)
	b[i]*=h;
    }
    //initialize tables of coefficients.
    void init()
    {
      switch(nsteps)
	{
	case 1:
	  a[0]=0.5; b[0]=1.;
	  break;
	case 2:
	  a[0]=0.25;              a[1]=0.25-sqrt(3.)/6.0;
	  a[2]=0.25+sqrt(3.)/6.0; a[3]=0.25;
	  b[0]=0.5; b[1]=0.5;
	  break;
	case 3:
	  a[0]=5./36.;   a[1]=2./9.-sqrt(15.)/15.;  a[2]=5./36.-sqrt(15.)/30.;

	  a[3]=5./36.+sqrt(15.)/24.;a[4]=2./9.; a[5]=5./36.-sqrt(15.)/24.;
	  a[6]=5./36.+sqrt(15.)/30.;a[7]=2./9.+sqrt(15.)/15.; a[8]=5./36.;

	  b[0]=5./18.; b[1]=4./9.; b[2]= 5./18.;
	  break;
	case 4:
	  a[0]=0.0869637112843634; a[1]=-0.0266041800849988; 
	  a[2]=0.0126274626894047; a[3]=-0.00355514968579570; 
	  a[4]=0.188118117499868; a[5]=0.163036288715637; 
	  a[6]=-0.0278804286024709; a[7]=0.00673550059453819; 
	  a[8]=0.167191921974188; a[9]=0.353953006033745; 
	  a[10]=0.163036288715637; a[11]=-0.0141906949311414; 
	  a[12]=0.177482572254522; a[13]=0.313445114741870; 
	  a[14]=0.352676757516271; a[15]=0.0869637112843631; 

	  b[0]=0.173927422568726;b[1]=0.326072577431275;
	  b[2]=0.326072577431272;b[3]=0.173927422568727;

	  break;
	case 5:
	  a[0]=0.0592317212640473; a[1]=-0.0195703643590761; 
	  a[2]=0.0112544008186429; a[3]=-0.00559379366081219; 
	  a[4]=0.00158811296786603; 
	  a[5]=0.128151005670045; 
	  a[6]=0.119657167624842; a[7]=-0.0245921146196421; 
	  a[8]=0.0103182806706834; a[9]=-0.00276899439876967; 

	  a[10]=0.113776288004224; a[11]=0.260004651680642; 
	  a[12]=0.142222222222222; a[13]=-0.0206903164309580; 
	  a[14]=0.00468715452387002;a[15]=0.121232436926864; 
	  a[16]=0.228996054579001; a[17]=0.309036559064089; 
	  a[18]=0.119657167624844; a[19]=-0.00968756314195124; 

	  a[20]=0.116875329560229; a[21]=0.244908128910497; 
	  a[22]=0.273190043625807; a[23]=0.258884699608758; 
	  a[24]=0.0592317212640469;
 
	  b[0]=0.118463442528094;b[1]=0.239314335249686;
	  b[2]=0.284444444444452;b[3]=0.239314335249681;
	  b[4]=0.118463442528096;

	  break;
	case 6:
	  a[0]=0.0428311230947926; a[1]=-0.0147637259971974; 
	  a[2]=0.00932505070647764; a[3]=-0.00566885804948372; 
	  a[4]=0.00285443331509940; a[5]=-0.000812780171264482; 

	  a[6]=0.0926734914303789; a[7]=0.0901903932620348; 
	  a[8]=-0.0203001022932395; a[9]=0.0103631562402468; 
	  a[10]=-0.00488719292803784; a[11]=0.00135556105548460; 

	  a[12]=0.0822479226128442; a[13]=0.196032162333245; 
	  a[14]=0.116978483643170; a[15]=-0.0204825277456566; 
	  a[16]=0.00798999189966233; a[17]=-0.00207562578486557; 

	  a[18]=0.0877378719744527; a[19]=0.172390794624405; 
	  a[20]=0.254439495032005; a[21]=0.116978483643183; 
	  a[22]=-0.0156513758091801; a[23]=0.00341432357674041; 

	  a[24]=0.0843066851341027; a[25]=0.185267979452103; 
	  a[26]=0.223593811046112; a[27]=0.254257069579565; 
	  a[28]=0.0901903932620078; a[29]=-0.00701124524078664; 

	  a[30]=0.0864750263608552; a[31]=0.177526353208971; 
	  a[32]=0.239625825335856; a[33]=0.224631916579810; 
	  a[34]=0.195144512521287; a[35]=0.0428311230948098; 

	  b[0]=0.0856622461895906;b[1]=0.180380786524065;
	  b[2]=0.233956967286382;b[3]=0.233956967286282;
	  b[4]=0.180380786524101;b[5]=0.0856622461895782;

	  break;
	case 7:
	  a[0]=0.0323712415422174; a[1]=-0.0114510172831839; 
	  a[2]=0.00763320387242361; a[3]=-0.00513373356322494; 
	  a[4]=0.00317505877368619; a[5]=-0.00160681903704639; 
	  a[6]=0.000458109523748723; 
	  a[7]=0.0700435413787261; 
	  a[8]=0.0699263478723193; a[9]=-0.0165900065788479; 
	  a[10]=0.00934962278344260; a[11]=-0.00539709193189702; 
	  a[12]=0.00264584386673054; a[13]=-0.000743850190170735; 

	  a[14]=0.0621539357873500; a[15]=0.152005522057831; 
	  a[16]=0.0954575126262809; a[17]=-0.0183752442154510; 
	  a[18]=0.00871256259847608; a[19]=-0.00395358015881123; 
	  a[20]=0.00107671561562619; 
	  a[21]=0.0663329286176852; 
	  a[22]=0.133595769223884; a[23]=0.207701880765971; 
	  a[24]=0.104489795918353; a[25]=-0.0167868555134101; 
	  a[26]=0.00625692652075678; a[27]=-0.00159044553324700; 
	  
	  a[28]=0.0636657674688082; a[29]=0.143806275903460; 
	  a[30]=0.182202462654094; a[31]=0.227354836052193; 
	  a[32]=0.0954575126263444; a[33]=-0.0121528263132131; 
	  a[34]=0.00258854729708305; 
	  a[35]=0.0654863332746147; 
	  a[36]=0.137206851877942; a[37]=0.196312117184484; 
	  a[38]=0.199629969053332; a[39]=0.207505031831386; 
	  a[40]=0.0699263478722039; a[41]=-0.00530105829425871; 

	  a[42]=0.0642843735606863; a[43]=0.141459514781745; 
	  a[44]=0.187739966478904; a[45]=0.214113325400010; 
	  a[46]=0.183281821380041; a[47]=0.151303713027863; 
	  a[48]=0.0323712415422803; 

	  b[0]=0.0647424830844479;b[1]=0.139852695744686;
	  b[2]=0.190915025252551;b[3]=0.208979591836794;
	  b[4]=0.190915025252465;b[5]=0.139852695744729;
	  b[6]=0.0647424830844194;

	  break;
	case 8:
	  a[0]=0.0253071340725941; a[1]=-0.00910594330597008; 
	  a[2]=0.00628083114703038; a[3]=-0.00448301561305498; 
	  a[4]=0.00307849136832668; a[5]=-0.00191767525463677; 
	  a[6]=0.000972757664059454; a[7]=-0.000277508327116878; 

	  a[8]=0.0547593217675543; a[9]=0.0555952586133436; 
	  a[10]=-0.0136397962357815; a[11]=0.00814970885836089; 
	  a[12]=-0.00521535208914705; a[13]=0.00313975298546331; 
	  a[14]=-0.00156493491094925; a[15]=0.000442802304342174; 

	  a[16]=0.0485875359989130; a[17]=0.120859524997173; 
	  a[18]=0.0784266614694695; a[19]=-0.0159751033618789; 
	  a[20]=0.00837173272022544; a[21]=-0.00464346586210404; 
	  a[22]=0.00222571477528533; a[23]=-0.000618805695250395; 

	  a[24]=0.0518655209705814; a[25]=0.106193490148348; 
	  a[26]=0.170671134274555; a[27]=0.0906709458446025; 
	  a[28]=-0.0160210413210331; a[29]=0.00724120656122215; 
	  a[30]=-0.00319781431036118; a[31]=0.000859236584265280; 

	  a[32]=0.0497550315609271; a[33]=0.114388331537049; 
	  a[34]=0.149612116377728; a[35]=0.197362933010200; 
	  a[36]=0.0906709458445396; a[37]=-0.0138178113355911; 
	  a[38]=0.00499702707833805; a[39]=-0.00125125282539103; 

	  a[40]=0.0512330738404461; a[41]=0.108964802451385; 
	  a[42]=0.161496788801106; a[43]=0.172970158968949; 
	  a[44]=0.197316995051035; a[45]=0.0784266614695357; 
	  a[46]=-0.00966900777052432; a[47]=0.00202673214628907; 

	  a[48]=0.0501714658408705; a[49]=0.112755452137598; 
	  a[50]=0.153713569953459; a[51]=0.186557243778223; 
	  a[52]=0.173192182830730; a[53]=0.170493119174751; 
	  a[54]=0.0555952586132666; a[55]=-0.00414505362234112; 

	  a[56]=0.0508917764723625; a[57]=0.110217759562524; 
	  a[58]=0.158770998193595; a[59]=0.178263400320667; 
	  a[60]=0.185824907302188; a[61]=0.150572491792004; 
	  a[62]=0.120296460532546; a[63]=0.0253071340726385; 

	  b[0]=0.0506142681452459;b[1]=0.111190517226646;
	  b[2]=0.156853322939014;b[3]=0.181341891689101;
	  b[4]=0.181341891689215;b[5]=0.156853322939014;
	  b[6]=0.111190517226618;b[7]=0.0506142681452175;

	  break;
	default:
	  throw GenericException("GaussianMethod, nsteps=",nsteps,
				 "(limited to 8)");
	}
    }
    //! destructor.
    ~GaussianMethod(){}
    //! access to a array.
    inline double A(int i,int j) const
    {
#ifdef DEBUG
      if(i<0||i>=nsteps||j<0||j>nsteps)
	throw GenericException("SymplecticRK::GaussianMethod::A(int i,int i), i",
			       i," > nsteps or < 0");
#endif
      return a[i*nsteps+j];
    }
  public:
    //! verify theorem of Cooper (see Hairer & Co)
    void verify()
    {
      for(int i=0;i<nsteps;i++)
	{
	  for(int j=0;j<nsteps;j++)
	    std::cout<<b[i]*A(i,j)+b[j]*A(j,i)-b[i]*b[j]<<" ";
	  std::cout<<std::endl;
	}
    }
  };
  // long double of g++ on X86/64.
  template<int nsteps> class GaussianMethod<nsteps,long double>
  {
  protected:
    typedef long double Double;
    Double a[nsteps*nsteps];
    Double b[nsteps],d[nsteps];
  
    //! constructor.
    GaussianMethod()
    {
      init();
    }
    //! multiply coefficients by h.
    //! \param h
    void change_h(double h)
    {
      init();
      for(int i=0;i<nsteps*nsteps;i++)
	a[i]*=h;
      for(int i=0;i<nsteps;i++)
	b[i]*=h;
    }
    //initialize the coefficient tables.
    void init()
    {
      switch(nsteps)
	{
	case 1:
	  a[0]=0.5; b[0]=1.;
	  break;
	case 2:
	  a[0]=0.25;              a[1]=0.25-sqrt(3.)/6.0;
	  a[2]=0.25+sqrt(3.)/6.0; a[3]=0.25;
	  b[0]=0.5; b[1]=0.5;
	  break;
	case 3:
	  a[0]=5./36.;   a[1]=2./9.-sqrt(15.)/15.;  a[2]=5./36.-sqrt(15.)/30.;

	  a[3]=5./36.+sqrt(15.)/24.;a[4]=2./9.; a[5]=5./36.-sqrt(15.)/24.;
	  a[6]=5./36.+sqrt(15.)/30.;a[7]=2./9.+sqrt(15.)/15.; a[8]=5./36.;

	  b[0]=5./18.; b[1]=4./9.; b[2]= 5./18.;
	  break;
	case 4:
	  a[0]=0.0869637112843634643432659873054999; a[1]=-0.0266041800849987933133851304769530; 
	  a[2]=0.0126274626894047245150568805746181; a[3]=-0.00355514968579568315691098184956967; 

	  a[4]=0.188118117499868071650685545087171; a[5]=0.163036288715636535656734012694499; 
	  a[6]=-0.0278804286024708952241511064189970; a[7]=0.00673550059453815551539866908570386; 

	  a[8]=0.167191921974188773171133305525295; a[9]=0.353953006033743966537619131807999; 
	  a[10]=0.163036288715636535656734012694504; a[11]=-0.0141906949311411429641535704761723; 

	  a[12]=0.177482572254522611843442956460568; a[13]=0.313445114741868346798411144814386; 
	  a[14]=0.352676757516271864626853155865953; a[15]=0.0869637112843634643432659873054978; 

	  b[0]=0.173927422568726928686531974610998;b[1]=0.326072577431273071313468025389005;
	  b[2]=0.326072577431273071313468025388998;b[3]=0.173927422568726928686531974611001;


	  break;
	case 5:
	  a[0]=0.0592317212640472718785660101799793; a[1]=-0.0195703643590760374926432140508840; 
	  a[2]=0.0112544008186429555527162442150908; a[3]=-0.00559379366081218487681772196447595; 
	  a[4]=0.00158811296786599853936524247059340; 
	  a[5]=0.128151005670045283496166848329514; 
	  a[6]=0.119657167624841617010322878708909; a[7]=-0.0245921146196422003893182516860039; 
	  a[8]=0.0103182806706833574089539450563559; a[9]=-0.00276899439876960304428263075887959; 

	  a[10]=0.113776288004224602528741273815365; a[11]=0.260004651680641518592405895187574; 
	  a[12]=0.142222222222222222222222222222224; a[13]=-0.0206903164309582845717601377697552; 
	  a[14]=0.00468715452386994122839074654459299; 
	  a[15]=0.121232436926864146801414651118838; 
	  a[16]=0.228996054578999876611691812361461; a[17]=0.309036559064086644833762696130449; 
	  a[18]=0.119657167624841617010322878708908; a[19]=-0.00968756314195073973903482796955498; 

	  a[20]=0.116875329560228545217766777889367; a[21]=0.244908128910495418897463479382297; 
	  a[22]=0.273190043625801488891728200229357; a[23]=0.258884699608759271513288971468703; 
	  a[24]=0.0592317212640472718785660101799801; 
	  b[0]=0.118463442528094543757132020359959;b[1]=0.239314335249683234020645757417818;
	  b[2]=0.284444444444444444444444444444446;b[3]=0.239314335249683234020645757417818;
	  b[4]=0.118463442528094543757132020359959;

	  break;
	case 6:
	  a[0]=0.0428311230947925862600740355431832; a[1]=-0.0147637259971974124753725910605206; 
	  a[2]=0.00932505070647775119143888450800328; a[3]=-0.00566885804948351190092125641621631; 
	  a[4]=0.00285443331509933513092928583011593; a[5]=-0.000812780171264762112299135651562771; 

	  a[6]=0.0926734914303788631865122917633204; a[7]=0.0901903932620346518924583784594292; 
	  a[8]=-0.0203001022932395859524940805242727; a[9]=0.0103631562402464237307199458065598; 
	  a[10]=-0.00488719292803767146341420376578953; a[11]=0.00135556105548506177551787075080051; 

	  a[12]=0.0822479226128438738077716511411292; a[13]=0.196032162333245006055759781563801; 
	  a[14]=0.116978483643172761847467585997390; a[15]=-0.0204825277456560976298590118653999; 
	  a[16]=0.00798999189966233579720442148030764; a[17]=-0.00207562578486633419359528915758238; 

	  a[18]=0.0877378719744515067137433602439476; a[19]=0.172390794624406967987712335438552; 
	  a[20]=0.254439495032001621324794183860172; a[21]=0.116978483643172761847467585997376; 
	  a[22]=-0.0156513758091757022708430246449401; a[23]=0.00341432357674129871237641994523798; 

	  a[24]=0.0843066851341001107446302003355620; a[25]=0.185267979452106975248330960684661; 
	  a[26]=0.223593811046099099964215226188192; a[27]=0.254257069579585109647429252519067; 
	  a[28]=0.0901903932620346518924583784594505; a[29]=-0.00701124524079369066636422067696167; 

	  a[30]=0.0864750263608499346324472067379218; a[31]=0.177526353208969968653987471088771; 
	  a[32]=0.239625825335829035595856428410946; a[33]=0.224631916579867772503496287486805; 
	  a[34]=0.195144512521266716260289347979362; a[35]=0.0428311230947925862600740355431697; 

	  b[0]=0.0856622461895851725201480710863630;b[1]=0.180380786524069303784916756918883;
	  b[2]=0.233956967286345523694935171994733;b[3]=0.233956967286345523694935171994807;
	  b[4]=0.180380786524069303784916756918840;b[5]=0.0856622461895851725201480710863723;


	  break;
	case 7:
	  a[0]=0.0323712415422174233176528581697705; a[1]=-0.0114510172831838702881645824731459; 
	  a[2]=0.00763320387242354492584664422163567; a[3]=-0.00513373356322534498195629758233859; 
	  a[4]=0.00317505877368563763683431730199577; a[5]=-0.00160681903704610585560610128347674; 
	  a[6]=0.000458109523749452982298319621633607; 
	  a[7]=0.0700435413787260762729814536065896; 
	  a[8]=0.0699263478723191669753669428559447; a[9]=-0.0165900065788477711644699061373328; 
	  a[10]=0.00934962278344333207631107766792839; a[11]=-0.00539709193189613785462120177242233; 
	  a[12]=0.00264584386673003737983031295579504; a[13]=-0.000743850190171923617331065816896978; 

	  a[14]=0.0621539357873498645358789291293530; a[15]=0.152005522057830992561321708847831; 
	  a[16]=0.0954575126262797362375924438722440; a[17]=-0.0183752442154518373892046007271730; 
	  a[18]=0.00871256259847518198378369475575228; a[19]=-0.00395358015881043812088052856667409; 
	  a[20]=0.00107671561562791673820514665018577; 
	  a[21]=0.0663329286176847005521322620413147; 
	  a[22]=0.133595769223882288417924053929653; a[23]=0.207701880765970782089300497781520; 
	  a[24]=0.104489795918367346938775510204075; a[25]=-0.0167868555134113096141156100370340; 
	  a[26]=0.00625692652075604553280983178223258; a[27]=-0.00159044553324985391682654570176758; 

	  a[28]=0.0636657674688069298971005696893485; a[29]=0.143806275903448772071614414278556; 
	  a[30]=0.182202462654084290491401192988720; a[31]=0.227354836052186531266755621135371; 
	  a[32]=0.0954575126262797362375924438723361; a[33]=-0.0121528263131926586105878231359725; 
	  a[34]=0.00258854729708498209942678721018559; 
	  a[35]=0.0654863332746067702526367821564340; 
	  a[36]=0.137206851877908296570903572756076; a[37]=0.196312117184455610329806089516901; 
	  a[38]=0.199629969053291361801239942740352; a[39]=0.207505031831407243639654793881746; 
	  a[40]=0.0699263478723191669753669428557538; a[41]=-0.00530105829429122963767573726699618; 

	  a[42]=0.0642843735606853936530073967178744; a[43]=0.141459514781684439806339986995354; 
	  a[44]=0.187739966478873834838350570442390; a[45]=0.214113325399960038859507317990687; 
	  a[46]=0.183281821380135927549338243522607; a[47]=0.151303713027822204238898468185135; 
	  a[48]=0.0323712415422174233176528581698874; 
	  b[0]=0.0647424830844348466353057163395277;b[1]=0.139852695744638333950733885711905;
	  b[2]=0.190915025252559472475184887744384;b[3]=0.208979591836734693877551020408465;
	  b[4]=0.190915025252559472475184887744212;b[5]=0.139852695744638333950733885712041;
	  b[6]=0.0647424830844348466353057163395215;

	  break;
	case 8:
	  a[0]=0.0253071340725940647881328385774905; a[1]=-0.00910594330597007502136365210466433; 
	  a[2]=0.00628083114703047398060942073780790; a[3]=-0.00448301561305475144191331423530033; 
	  a[4]=0.00307849136832677988985383064911911; a[5]=-0.00191767525463695234092563511949373; 
	  a[6]=0.000972757664059263526724523824086770; a[7]=-0.000277508327116919222898446613782437; 

	  a[8]=0.0547593217675543202831907973850022; a[9]=0.0555952586133436176360889986065602; 
	  a[10]=-0.0136397962357816692530306620699767; a[11]=0.00814970885836055053604042748372709; 
	  a[12]=-0.00521535208914715338024336977464078; a[13]=0.00313975298546366894234500690115526; 
	  a[14]=-0.00156493491094894237579511140442712; a[15]=0.000442802304342237815626944634684615; 

	  a[16]=0.0485875359989128809431601473474387; a[17]=0.120859524997173167441653743003486; 
	  a[18]=0.0784266614694718218344905504966551; a[19]=-0.0159751033618784314756701138556953; 
	  a[20]=0.00837173272022616378691032206439651; a[21]=-0.00464346586210447979012617007024398; 
	  a[22]=0.00222571477528489971831530140788826; a[23]=-0.000618805695250515367603304988544819; 

	  a[24]=0.0518655209705812345653120779649658; a[25]=0.106193490148348406878869450082592; 
	  a[26]=0.170671134274553621284710784603989; a[27]=0.0906709458445904957412876123192421; 
	  a[28]=-0.0160210413210250131687052177937839; a[29]=0.00724120656122226986180306301493387; 
	  a[30]=-0.00319781431036077032248274309541152; a[31]=0.000859236584264852689466901723355262; 

	  a[32]=0.0497550315609232768867987754316291; a[33]=0.114388331537048005594660740308584; 
	  a[34]=0.149612116377721373807178037978341; a[35]=0.197362933010206004651280442432407; 
	  a[36]=0.0906709458445904957412876123195648; a[37]=-0.0138178113356099776157296836107681; 
	  a[38]=0.00499702707833882839330854713054402; a[39]=-0.00125125282539310498904640081000118; 

	  a[40]=0.0512330738404386449438689821435367; a[41]=0.108964802451402335553862695805328; 
	  a[42]=0.161496788801048123459107271063489; a[43]=0.172970158968954827695664902574344; 
	  a[44]=0.197316995051059422958245338494339; a[45]=0.0784266614694718218344905504961681; 
	  a[46]=-0.00966900777048593216947574579017578; a[47]=0.00202673214627524863310552980752587; 

	  a[48]=0.0501714658408458917606387325203484; a[49]=0.112755452137636177647973108617814; 
	  a[50]=0.153713569953479974726636094092155; a[51]=0.186557243778328144862818594413577; 
	  a[52]=0.173192182830820440946534797154848; a[53]=0.170493119174725312922011763063340; 
	  a[54]=0.0555952586133436176360889986071485; a[55]=-0.00414505362236619070692512023016322; 

	  a[56]=0.0508917764723050487991641237688210; a[57]=0.110217759562627971745453473389329; 
	  a[58]=0.158770998193580596009906736112684; a[59]=0.178263400320854211592721393989790; 
	  a[60]=0.185824907302235742924488538873883; a[61]=0.150572491791913169688371680256102; 
	  a[62]=0.120296460532657310293541649317760; a[63]=0.0253071340725940647881328385772172; 

	  b[0]=0.0506142681451881295762656771549901;b[1]=0.111190517226687235272177997213269;
	  b[2]=0.156853322938943643668981100993362;b[3]=0.181341891689180991482575224638897;
	  b[4]=0.181341891689180991482575224638404;b[5]=0.156853322938943643668981100993954;
	  b[6]=0.111190517226687235272177997213023;b[7]=0.0506142681451881295762656771550147;

	  break;
	default:
	  throw GenericException("GaussianMethod, nsteps=",nsteps,
				 "(limited to 8)");
	}
    }
    //! destructor.
    ~GaussianMethod(){}
    //! access to a array.
    inline Double A(int i,int j) const
    {
#ifdef DEBUG
      if(i<0||i>=nsteps||j<0||j>nsteps)
	throw GenericException("SymplecticRK::GaussianMethod::A(int i,int i), i",
			       i," > nsteps or < 0");
#endif
      return a[i*nsteps+j];
    }
  public:
    //! verify theorem of Cooper (see Hairer & Co)
    void verify()
    {
      for(int i=0;i<nsteps;i++)
	{
	  for(int j=0;j<nsteps;j++)
	    std::cout<<b[i]*A(i,j)+b[j]*A(j,i)-b[i]*b[j]<<" ";
	  std::cout<<std::endl;
	}
    }
  };
}
#endif
