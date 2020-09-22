<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform"><xsl:template match="/">
<html>
<head>
<title>Orange xml preview</title>
<meta http-equiv="content-type" content="text/html;
charset=ISO-8859-1" />
<style>
  <![CDATA[
    .band{font-family: tahoma; font-size: 9pt; color: #000000}
    .header{font-family: tahoma; font-size: 9pt; color: #000000}
    .footer{font-family: tahoma; font-size: 9pt; color: #000000}
    .rowfooter{font-family: tahoma; font-size: 9pt; color: #000000}
    .group{font-family: tahoma; font-size: 9pt; color: #000000}
  ]]>
  </style>
</head>
  <body bgcolor="#c0c0c0">
    <table border="1" cellspacing="0" cellpadding="1" bgcolor="#c0c0c0"><tr><td>
    <table border="0" cellspacing="1" cellpadding="2" bgcolor="#c0c0c0">
      <tr valign="top" class="header" width="0" bgcolor="#F0F0F0">
        <td width="10">NUM</td>
        <td width="0">EMPNO</td>
        <td width="0">ENAME</td>
        <td width="0">JOB</td>
        <td width="0">MGR</td>
        <td width="0">HIREDATE</td>
        <td width="0">SAL</td>
        <td width="0">COMM</td>
        <td width="0">DEPTNO</td>
      </tr>
      <xsl:for-each select="/ROOT/RECORD">
      <tr>
        <td  nowrap="true" align="left" bgcolor="FFFFFF" class="group"><xsl:value-of select="./NUM"/></td>
        <td  nowrap="true" align="left" bgcolor="FFFFFF" class="group"><xsl:value-of select="./EMPNO"/></td>
        <td  nowrap="true" align="left" bgcolor="FFFFFF" class="group"><xsl:value-of select="./ENAME"/></td>
        <td  nowrap="true" align="left" bgcolor="FFFFFF" class="group"><xsl:value-of select="./JOB"/></td>
        <td  nowrap="true" align="left" bgcolor="FFFFFF" class="group"><xsl:value-of select="./MGR"/></td>
        <td  nowrap="true" align="left" bgcolor="FFFFFF" class="group"><xsl:value-of select="./HIREDATE"/></td>
        <td  nowrap="true" align="left" bgcolor="FFFFFF" class="group"><xsl:value-of select="./SAL"/></td>
        <td  nowrap="true" align="left" bgcolor="FFFFFF" class="group"><xsl:value-of select="./COMM"/></td>
        <td  nowrap="true" align="left" bgcolor="FFFFFF" class="group"><xsl:value-of select="./DEPTNO"/></td>
      </tr>
      </xsl:for-each>
    </table></td></tr>
  </table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>
