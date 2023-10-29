#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("shrubbery creation", 145, 137)
{
	this->target = "SCF";
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &obj ):AForm(obj.getName(), 145, 137)
{
	this->setSign(obj.getSign());
	this->target = obj.target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ):AForm("shrubbery creation", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator =(const ShrubberyCreationForm &rhs)
{
	if (&rhs != this)
		this->setSign(rhs.getSign());
	this->target = rhs.target;
	return (*this);
}

void				ShrubberyCreationForm::beSigned(Bureaucrat const &B)
{
	if (B.getGrade() > this->getRequeredSignGrade())
		throw ShrubberyCreationForm::GradeTooLowException();
	this->setSign(true);
}

std::string const	&ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void		        ShrubberyCreationForm::execute(Bureaucrat const &B) const
{
    this->validation(B);
	std::ofstream outfile(this->target + "_shrubbery");
	outfile  << "                                   *;.                                        " << std::endl
			<< "                    uz              ;*.                                       " << std::endl
			<< "              *o1vv.             . ~-o~;~         na+                         " << std::endl
			<< "          .n u1 ua . ;o         ^.-1a *o                                      " << std::endl
			<< "      i!;   ~ivn^z   -v.          a. ^va          uz                          " << std::endl
			<< "      ;+*zvu    zz!%z; o.         . uoa v       .++                           " << std::endl
			<< "    1aia-ii.vv;aio!~!~o;n-a        *zaua^         *vuo^.;z                    " << std::endl
			<< "        i13!31u~;n*ni!~n; u~      v-+.u!nn       aazn ~-      o.              " << std::endl
			<< "          1z1%!zu+o+u noon;~;      ana ^+ ~a.  .   v ; -    ;vza              " << std::endl
			<< "            !!i.ui!a3iu8uau u      +nv;o ^+o    ; ~o* ~     n ;               " << std::endl
			<< "             ^6ii333%o86%.auv..    .z+1  u ;  z-;~v !o  o~;a                  " << std::endl
			<< "               66%6u6!83!i.zuau  ~..un ^! vo  1 ~ ;n8 uzu.                    " << std::endl
			<< "             3;;!!3z!36-o11.n*.i*^u1u.ua;~u ~;ivua;*%a.  nv                   " << std::endl
			<< "             33336$!i6ii!8u1uaoa~uu !ua*1uv*z^16izz~ovvn                      " << std::endl
			<< "    a;        !836886i3#1i63!31v3a!a8i+zo+u ui azn   u.  z*^;v ~              " << std::endl
			<< "    a.- o;;      u1!3i!36iaiviz8nn%i^i1 i1ovzu uzai     a v.~n    ;zv         " << std::endl
			<< "     v.11n;       .u.3i1i63ia!1zi8ouu1 ;~zazo;+~u+aaa-n.;v3 oz .  n ;~+;      " << std::endl
			<< "     uz 1ii!o      u -8! v1 83iav;n1-;z.;u^;;azn;^!n~o1.+1 a1i.n  a +nun^v-   " << std::endl
			<< "        1uiuav         .i3vi!81izuv!a   i!i!16;!3u z;uvz- ni       166u. ~*a  " << std::endl
			<< "        n nu1i1!-  !^31+%3ui66!%~uuzzz11iiauiiu1!1!ua1zvv          a+*1o~;u*  " << std::endl
			<< "             3a i1a  ! *!66uii!361zn!13.a3i!31i11u.u3u .zv    -^^1uzzvnn *    " << std::endl
			<< "          i zz3!i6avi ;616%!3163%666836333i1!!1118!n+!oz     ;3aav ~          " << std::endl
			<< "           ^ i8383i3!..8633ovni36$%$!88!3863vzii361z -an    .aiiauzn          " << std::endl
			<< "            ~3!!38$66i3.6o~3~.3.! %361883v3$izn13a11zi!u  z!i3*i1z o          " << std::endl
			<< "      1       v~8836i3!31n*63%!izn!z866338!$1aai81ai1zu ~!!!o. -   *n-        " << std::endl
			<< "    u1z1v  ^o!6.3~%8uz6%z%%u383o!1$uvzio^z6%%8o6!!! uv  aiu!u  311 +za-~~~    " << std::endl
			<< "       uua   u-63 !~!8%$%68663!uvvvu38inv~nv88!8a!;3!.onn+a!z.o316u1vv-ov     " << std::endl
			<< "    1ui 1! !1u!!*68%o%86 636^i%!%uvuz61!$63o33!3n   3i81iu33;13!.z~a          " << std::endl
			<< " 11o    !^3;z!. 33~*u8%*! 388!i!vvizzz8$%+u^+6$zi33ui1z6uouni                 " << std::endl
			<< "       iio.~1!uuv1!n333u%no.1vz%v68.$6i#86.!+ 6%!688iza3 .i                   " << std::endl
			<< "   .  ! -ii!!3ii!z6v31a83!%u11.1vz~!1663vzn-3*86i6o36zu1*  - o*ou             " << std::endl
			<< "      3686 6a%33%%8$&^+o16~iu38u%iun!668$1 i!88  6n!3n !-i 1                  " << std::endl
			<< "              v 66 1%8#8838!*-+3n3%!613 !uu8!86%6%i                           " << std::endl
			<< "                 v818.ii88$%8!u%8%1-%-v!iz!a1. $1 !1  ni                      " << std::endl
			<< "                  68z-%3683a!3%~3   68%883!oz88!3i3 *;^1                      " << std::endl
			<< "                  383o18n3v+8 83%8$&38u%!u3v!   u                             " << std::endl
			<< "                       %%8$ %%%i%18%-1$% %! i  .                              " << std::endl
			<< "                   3    +i%-.!666&6!!1%&$86u.v1$ia8683in~-i-*                 " << std::endl
			<< "                    3.+nz1oa %.%%%i1  $$ 6 %z 6  u.iz!6 !v+                   " << std::endl
			<< "                      33i33318 *  .    $n!!8n.i    !a -i                      " << std::endl
			<< "                         6u!!6ii6i     &$&&38i;.                              " << std::endl
			<< "                       ii63z366$%& - 666i%3!331u                              " << std::endl
			<< "                      n1  33i*1+;61.a;8$%3%                                   " << std::endl
			<< "                      38u1%-!i36!838*!881i!va                                 " << std::endl
			<< "                        3 ii661$83%a!3$$o.8 +                                 " << std::endl
			<< "                              i^!!$^%ui386va                                  " << std::endl
			<< "                              !-. 8-~ 33v  izza                               " << std::endl
			<< "                                       1                                      ";	
	outfile.close();    
}

std::ostream& operator<<(std::ostream &COUT, ShrubberyCreationForm const &rhs)
{
	COUT << "_________________ FORM INFO _________________" << std::endl;
	COUT << "Name: " << rhs.getName() << std::endl;
	COUT << "Target: " << rhs.getTarget() << std::endl;
	COUT << "Sign: " << (rhs.getSign() == 1 ? "True" : "False") << std::endl;
	COUT << "Requered Sign Grade: " << rhs.getRequeredSignGrade() << std::endl;
	COUT << "Requered Exec Grade: " << rhs.getRequeredExecGrade() << std::endl;
	COUT << "_____________________________________________" << std::endl;
	return COUT;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}