/******************************************************************************
 *
 * 
 *
 * Copyright (C) 1997-2000 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 */

/*
 *
 * Nickolay Semyonov
 * Andrey V. Stolyarov released Feb 14, 2001
 * Alexandr V. Chelpanov <cav@cryptopro.ru> released Apr 21, 2001
 *
 * �������� ��� �� ������� �������� �� ������� ���� �� email (��. ����)
 *
 * ��� �������� ���������� ����� list � documentation ������.
 *
 * Modules ���������� ��� ������, ��� ��� ������ ���� ����� � ������� 
 *  �������� ����������� � ��������� ������ ��� ������� ����������, �����
 *  � ��., ��� � ������ ������ �� ������ ��������, ��� ����� ��� 
 *  ��������������� ������� � doxygen ��������� \group.
 * 
 * ������� �� �������������� decode �������� ���������, ��� ����� ��������
 *  � ������������� ����� � ��� ����� ������� ���� ������.
 *
 * ������ ������������ ��� �������� related functions - "����������� � ������
 *  �������", � �� "��������� �������", ��� ����� �� ��� ��� ���� ���� ������
 *  related to class, � ��� related to template, package � �.�. ���������
 *  ��������� �������� ����������� member.
 *
 * �� ����������� ��� �������� members ����������� ������ ���� ���� member
 *  ��������. 
 *
 * Compounds ���������� ��� ������, �� ����������.
 *
 * ����������� ���������� ?? �������� ��������.
 *
 * �������������: Vitaly A. Repin <vitaly@radio.hop.stu.neva.ru>
 */

#ifndef TRANSLATOR_RU_H
#define TRANSLATOR_RU_H

class TranslatorRussian : public TranslatorAdapter_1_2_13
{
  private:
    /*! The Decode() inline assumes the source written in the 
        Koi8-R encoding (maintainer dependent). 
     */
    inline QCString decode(const QCString & sInput)
    { 
#ifdef _WIN32
      return Koi8RToWindows1251(sInput);
#else
      return sInput;
#endif
    }

  public:
    /*! Used for identification of the language. */
    virtual QCString idLanguage()
    { return "russian"; }

    /* Used to get the command(s) for the language support. */
    virtual QCString latexLanguageSupportCommand()
#ifdef _WIN32
    { return "\\usepackage[cp1251]{inputenc}\n\\usepackage[russian]{babel}\n"; }
#else
    { return "\\usepackage[koi8-r]{inputenc}\n\\usepackage[russian]{babel}\n"; }
#endif

    /*! return the language charset. This will be used for the HTML output */
    virtual QCString idLanguageCharset()
#ifdef _WIN32
    { return "Windows-1251"; }
#else
    { return "koi8-r"; }
#endif

    // --- Language translation methods -------------------

    /*! used in the compound documentation before a list of related functions. */
    virtual QCString trRelatedFunctions()
    { return decode("����������� � ������ �������"); }

    /*! subscript for the related functions. */
    virtual QCString trRelatedSubscript()
    { return decode("(�� ����� ������)"); }

    /*! header that is put before the detailed description of files, classes and namespaces. */
    virtual QCString trDetailedDescription()
    { return decode("��������� ��������"); }

    /*! header that is put before the list of typedefs. */
    virtual QCString trMemberTypedefDocumentation()
    { return decode("����������� �����"); }

    /*! header that is put before the list of enumerations. */
    virtual QCString trMemberEnumerationDocumentation()
    { return decode("������������"); }

    /*! header that is put before the list of member functions. */
    virtual QCString trMemberFunctionDocumentation()
    { return decode("������"); }

    /*! header that is put before the list of member attributes. */
    virtual QCString trMemberDataDocumentation()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return decode( "����" );
      }
      else
      {
        return decode( "������ ������" );
      }
    }

    /*! this is the text of a link put after brief descriptions. */
    virtual QCString trMore()
    { return decode("���������..."); }

    /*! put in the class documentation */
    /* Dosn't use when optimization for C is on. */
    virtual QCString trListOfAllMembers()
    {
      return decode( "������ ������ ������ ������" );
    }

    /*! used as the title of the "list of all members" page of a class */
    /* Dosn't use when optimization for C is on. */
    virtual QCString trMemberList()
    {
      return decode( "C����� ������ ������" );
    }

    /*! this is the first part of a sentence that is followed by a class name */
    /* Dosn't use when optimization for C is on. */
    virtual QCString trThisIsTheListOfAllMembers()
    { return decode("������ ������ ������ ������ "); }

    /*! this is the remainder of the sentence after the class name */
    /* Dosn't use when optimization for C is on. */
    virtual QCString trIncludingInheritedMembers()
    { return decode(", ������� ����������� �� �������� ������"); }

    /*! this is put at the author sections at the bottom of man pages.
     *  parameter s is name of the project name.
     */
    virtual QCString trGeneratedAutomatically(const char *s)
    { QCString result=decode("������������� ������� Doxygen");
      if (s) result+=decode(" ��� ")+s;
      result+=decode(" �� ��������� ������."); 
      return result;
    }

    /*! put after an enum name in the list of all members */
    virtual QCString trEnumName()
    { return decode("������������"); }

    /*! put after an enum value in the list of all members */
    virtual QCString trEnumValue()
    { return decode("�������� ������������"); }

    /*! put after an undocumented member in the list of all members */
    virtual QCString trDefinedIn()
    { return decode("���������� �"); }

    // quick reference sections

    /*! This is put above each page as a link to the list of all groups of 
     *  compounds or files (see the \\group command).
     */
    virtual QCString trModules()
    { return decode("������"); }

    /*! This is put above each page as a link to the class hierarchy */
    virtual QCString trClassHierarchy()
    { return decode("�������� �������"); }

    /*! This is put above each page as a link to the list of annotated classes */
    virtual QCString trCompoundList()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return decode( "��������� ������" );
      }
      else
      {
        return decode( "������" );
      }
    }

    /*! This is put above each page as a link to the list of documented files */
    virtual QCString trFileList()
    { return decode("�����"); }

    /*! This is put above each page as a link to the list of all verbatim headers */
    virtual QCString trHeaderFiles()
    { return decode("������������ �����"); }

    /*! This is put above each page as a link to all members of compounds. */
    virtual QCString trCompoundMembers()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return decode( "���� ��������" );
      }
      else
      {
        return decode( "����� �������" );
      }
    }

    /*! This is put above each page as a link to all members of files. */
    /*??*/
    virtual QCString trFileMembers()
    {
      return decode( "����� �����" );
    }

    /*! This is put above each page as a link to all related pages. */
    virtual QCString trRelatedPages()
    /* ?? ������� �������� "��. �����: " ����� �������, �� �� � ���������,
     ��� � ������ ������. */
    { return decode("��������"); }

    /*! This is put above each page as a link to all examples. */
    virtual QCString trExamples()
    { return decode("�������"); }

    /*! This is put above each page as a link to the search engine. */
    virtual QCString trSearch()
    { return decode("�����"); }

    /*! This is an introduction to the class hierarchy. */
    virtual QCString trClassHierarchyDescription()
    { return decode("�������� �������."); }

    /*! This is an introduction to the list with all files. */
    virtual QCString trFileListDescription(bool extractAll)
    {
      QCString result="������ ������ ";
      if (!extractAll) result+="����������������� ";
      result+="������.";
      return decode(result);
    }

    /*! This is an introduction to the annotated compound list. */
    virtual QCString trCompoundListDescription()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return decode( "��������� ������ � �� ������� ���������." );
      }
      else
      {
        return decode( "������ � �� ������� ���������." );
      }
    }

    /*! This is an introduction to the page with all class members. */
    virtual QCString trCompoundMembersDescription(bool extractAll)
    {
        QCString result="������ ���� ";
        if(!extractAll) result+="����������������� ";
        if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
          result+="������ �������� ������ �� �������� �� ";
        else
          result+="������ ������� �� �������� �� ";
        if(extractAll)
        {
          if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
            result+="������������ �� ��������� ��� ������� �����.";
          else
            result+="������������ �� ������ ��� ������� �����.";
        }
        else
        {
          if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
            result += "���������";
          else
            result += "������";
          result+=", � ������� ��� �����������.";
        }
        return decode( result );
    }

    /*! This is an introduction to the page with all file members. */
    virtual QCString trFileMembersDescription(bool extractAll)
    {
      QCString result="������ ���� ";
      if (!extractAll) result+="����������������� ";

      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        result+="�������, ����������, ����������������, "
                "������������ � ����������� �����";
      }
      else
      {
        result+="������ ������ ";
      }
      result+=" �� �������� �� ";
      if (extractAll)
        result+="�����, � ������� ��� �����������.";
      else
        result+="������������.";
      return decode( result );
    }

    /*! This is an introduction to the page with the list of all header files. */
    virtual QCString trHeaderFilesDescription()
    { return decode("������ ������ ������������ ������."); }

    /*! This is an introduction to the page with the list of all examples */
    virtual QCString trExamplesDescription()
    { return decode("������ ������ ��������."); }

    /*! This is an introduction to the page with the list of related pages */
    virtual QCString trRelatedPagesDescription()
    { return decode("������ ������ �������������� ��������."); }

    /*! This is an introduction to the page with the list of class/file groups */
    virtual QCString trModulesDescription()
    { return decode("������ ������ �����."); }

    /*! This sentences is used in the annotated class/file lists if no brief
     * description is given. 
     */
    virtual QCString trNoDescriptionAvailable()
    { return decode("�������� ����������"); }

    // index titles (the project name is prepended for these) 


    /*! This is used in HTML as the title of index.html. */
    virtual QCString trDocumentation()
    { return decode("������������"); }

    /*! This is used in LaTeX as the title of the chapter with the 
     * index of all groups.
     */
    virtual QCString trModuleIndex()
    { return decode("���������� ��������� �����"); }

    /*! This is used in LaTeX as the title of the chapter with the 
     * class hierarchy.
     */
    virtual QCString trHierarchicalIndex()
    { return decode("������������� ������ �������"); }

    /*! This is used in LaTeX as the title of the chapter with the 
     * annotated compound index.
     */
    virtual QCString trCompoundIndex()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return decode( "���������� ��������� �������� ������" );
      }
      else
      {
        return decode( "���������� ��������� �������" );
      }
    }

    /*! This is used in LaTeX as the title of the chapter with the
     * list of all files.
     */
    virtual QCString trFileIndex()
    { return decode( "������ ������" ); }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all groups.
     */
    virtual QCString trModuleDocumentation()
    { return decode("������"); }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all classes, structs and unions.
     */
    virtual QCString trClassDocumentation()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return decode( "��������� ������" );
      }
      else
      {
        return decode( "������" );
      }
    }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all files.
     */
    virtual QCString trFileDocumentation()
    { return decode("�����"); }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all examples.
     */
    virtual QCString trExampleDocumentation()
    { return decode("�������"); }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all related pages.
     */
    virtual QCString trPageDocumentation()
    { return decode("������������ ��������"); }

    /*! This is used in LaTeX as the title of the document */
    virtual QCString trReferenceManual()
    { return decode("����������"); }

    /*! This is used in the documentation of a file as a header before the 
     *  list of defines
     */
    virtual QCString trDefines()
    { return decode("�������"); }

    /*! This is used in the documentation of a file as a header before the 
     *  list of function prototypes
     */
    virtual QCString trFuncProtos()
    { return decode("��������� �������"); }

    /*! This is used in the documentation of a file as a header before the 
     *  list of typedefs
     */
    virtual QCString trTypedefs()
    { return decode("����������� �����"); }

    /*! This is used in the documentation of a file as a header before the 
     *  list of enumerations
     */
    virtual QCString trEnumerations()
    { return decode("������������"); }

    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) functions
     */
    virtual QCString trFunctions()
    { return decode("�������"); }

    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) variables
     */
    virtual QCString trVariables()
    { return decode("����������"); }

    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) variables
     */
    virtual QCString trEnumerationValues()
    { return decode("�������� ������������"); }

    /*! This is used in the documentation of a file before the list of
     *  documentation blocks for defines
     */
    virtual QCString trDefineDocumentation()
    { return decode("�������"); }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for function prototypes
     */
    virtual QCString trFunctionPrototypeDocumentation()
    { return decode("��������� �������"); }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for typedefs
     */
    virtual QCString trTypedefDocumentation()
    { return decode("����"); }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for enumeration types
     */
    virtual QCString trEnumerationTypeDocumentation()
    { return decode("������������"); }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for enumeration values
     */
    virtual QCString trEnumerationValueDocumentation()
    { return decode("�������� ������������"); }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for functions
     */
    virtual QCString trFunctionDocumentation()
    { return decode("�������"); }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for variables
     */
    virtual QCString trVariableDocumentation()
    { return decode("����������"); }

    /*! This is used in the documentation of a file/namespace/group before 
     *  the list of links to documented compounds
     */
    virtual QCString trCompounds()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return decode( "��������� ������" );
      }
      else
      { 
        return decode( "������" );
      }

    }

    /*! This is used in the documentation of a group before the list of 
     *  links to documented files
     */
    /*! This is used in the standard footer of each page and indicates when 
     *  the page was generated 
     */
    virtual QCString trGeneratedAt(const char *date,const char *projName)
    { 
      QCString result=decode("������������ ");
      if (projName) result+=decode("�� ")+projName;
      result+=decode(". ��������� ���������: ")+date;
      result+=decode(". ������� ��������");
      return result;
    }
    /*! This is part of the sentence used in the standard footer of each page.
     */
    virtual QCString trWrittenBy()
    {
      return decode("�����:");
    }

    /*! this text is put before a class diagram */
    virtual QCString trClassDiagram(const char *clName)
    {
      return decode("���� ������������:")+clName+":";
    }

    /*! this text is generated when the \\internal command is used. */
    virtual QCString trForInternalUseOnly()
    { return decode("������ ��� ����������� �������������"); }

    /*! this text is generated when the \\reimp command is used. */
    virtual QCString trReimplementedForInternalReasons()
    /*??*/
    { return decode("�������� �� ���������� ��������"); 
    }

    /*! this text is generated when the \\warning command is used. */
    virtual QCString trWarning()
    { return decode("��������������"); }

    /*! this text is generated when the \\bug command is used. */
    virtual QCString trBugsAndLimitations()
    { return decode("������ � �����������"); }

    /*! this text is generated when the \\version command is used. */
    virtual QCString trVersion()
    { return decode("������"); }

    /*! this text is generated when the \\date command is used. */
    virtual QCString trDate()
    { return decode("����"); }

    /*! this text is generated when the \\return command is used. */
    virtual QCString trReturns()
    { return decode("����������"); }

    /*! this text is generated when the \\sa command is used. */
    virtual QCString trSeeAlso()
    { return decode("��. �����"); }

    /*! this text is generated when the \\param command is used. */
    virtual QCString trParameters()
    { return decode("���������"); }

    /*! this text is generated when the \\exception command is used. */
    virtual QCString trExceptions()
    { return decode("����������"); }

    /*! this text is used in the title page of a LaTeX document. */
    virtual QCString trGeneratedBy()
    { return decode("������� ��������"); }
    
//////////////////////////////////////////////////////////////////////////
// new since 0.49-990307 
//////////////////////////////////////////////////////////////////////////
    
    /*! used as the title of page containing all the index of all namespaces. */
    virtual QCString trNamespaceList()
    { return decode("������������ ����"); }

    /*! used as an introduction to the namespace list */
    virtual QCString trNamespaceListDescription(bool extractAll)
    {
      QCString result="������ ������ ";
      if (!extractAll) result+="����������������� ";
      result+="����������� ����.";
      return decode(result);
    }

    /*! used in the class documentation as a header before the list of all
     *  friends of a class
     */
    virtual QCString trFriends()
    { return decode("������"); }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990405
//////////////////////////////////////////////////////////////////////////
    
    /*! used in the class documentation as a header before the list of all
     * related classes 
     */
    virtual QCString trRelatedFunctionDocumentation()
    { return decode("������������ �� ������� ������ � �������� �������������"
        " � ������"); }
    
//////////////////////////////////////////////////////////////////////////
// new since 0.49-990425
//////////////////////////////////////////////////////////////////////////

    /*! used as the title of the HTML page of a class/struct/union */
    virtual QCString trCompoundReference(const char *clName,
                                 ClassDef::CompoundType compType,
                                 bool isTemplate)
    {
      QCString result;
      if (isTemplate) 
      {
        result="������ ";
        switch(compType)
        {
          case ClassDef::Class:  result+="������"; break;
          case ClassDef::Struct: result+="���������"; break;
          case ClassDef::Union:  result+="�����������"; break;
          case ClassDef::Interface:  result+="����������"; break;
          case ClassDef::Exception:  result+="����������"; break;
        }
      }
      else
      {
        switch(compType)
        {
          case ClassDef::Class:  result+="�����"; break;
          case ClassDef::Struct: result+="���������"; break;
          case ClassDef::Union:  result+="�����������"; break;
          case ClassDef::Interface:  result+="���������"; break;
          case ClassDef::Exception:  result+="����������"; break;
        }
      }
      result+=" ";
      return decode(result)+clName;
    }

    /*! used as the title of the HTML page of a file */
    virtual QCString trFileReference(const char *fileName)
    {
      return decode("���� ")+fileName;
    }

    /*! used as the title of the HTML page of a namespace */
    virtual QCString trNamespaceReference(const char *namespaceName)
    {
      return decode("������������ ���� ")+namespaceName;
    }
    
    virtual QCString trPublicMembers()
    { return decode("�������� �����"); }
    virtual QCString trPublicSlots()
    { return decode("�������� �����"); }
    virtual QCString trSignals()
    { return decode("�������"); }
    virtual QCString trStaticPublicMembers()
    { return decode("�������� ����������� �����"); }
    virtual QCString trProtectedMembers()
    { return decode("���������� �����"); }
    virtual QCString trProtectedSlots()
    { return decode("���������� �����"); }
    virtual QCString trStaticProtectedMembers()
    { return decode("���������� ����������� �����"); }
    virtual QCString trPrivateMembers()
    { return decode("�������� �����"); }
    virtual QCString trPrivateSlots()
    { return decode("�������� �����"); }
    virtual QCString trStaticPrivateMembers()
    { return decode("�������� ����������� �����"); }
    
    /*! this function is used to produce a comma-separated list of items.
     *  use generateMarker(i) to indicate where item i should be put.
     */
    virtual QCString trWriteList(int numEntries)
    {
      QCString result;
      int i;
      // the inherits list contain `numEntries' classes
      for (i=0;i<numEntries;i++) 
      {
        // use generateMarker to generate placeholders for the class links!
        result+=generateMarker(i); // generate marker for entry i in the list 
                                   // (order is left to right)
        
        if (i!=numEntries-1)  // not the last entry, so we need a separator
        {
          if (i<numEntries-2) // not the fore last entry 
            result+=", ";
          else                // the fore last entry
            result+=decode( " � " );
        }
      }
      return result; 
    }
    
    /*! used in class documentation to produce a list of base classes,
     *  if class diagrams are disabled.
     */
    virtual QCString trInheritsList(int numEntries)
    {
      return decode("������� ������:")+trWriteList(numEntries)+".";
    }

    /*! used in class documentation to produce a list of super classes,
     *  if class diagrams are disabled.
     */
    virtual QCString trInheritedByList(int numEntries)
    {
      return decode("����������� ������:")+trWriteList(numEntries)+".";
    }

    /*! used in member documentation blocks to produce a list of 
     *  members that are hidden by this one.
     */
    virtual QCString trReimplementedFromList(int numEntries)
    {
      return decode("�������������� ����� ������ ")+trWriteList(numEntries)+".";
    }

    /*! used in member documentation blocks to produce a list of
     *  all member that overwrite the implementation of this member.
     */
    virtual QCString trReimplementedInList(int numEntries)
    {
      return decode("���������������� � ")+trWriteList(numEntries)+".";
    }

    /*! This is put above each page as a link to all members of namespaces. */
    virtual QCString trNamespaceMembers()
    { return decode("����� ������������ ����"); }

    /*! This is an introduction to the page with all namespace members */
    virtual QCString trNamespaceMemberDescription(bool extractAll)
    {
      QCString result="������ ������ ";
      if (!extractAll) result+="����������������� ";
      result+="������ ����������� ����.";
      return decode(result);
    }

    /*! This is used in LaTeX as the title of the chapter with the 
     *  index of all namespaces.
     */
    virtual QCString trNamespaceIndex()
    { return decode("���������� ��������� ������������ ����"); }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all namespaces.
     */
    virtual QCString trNamespaceDocumentation()
    { return decode("������������ ����"); }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990522
//////////////////////////////////////////////////////////////////////////

    /*! This is used in the documentation before the list of all
     *  namespaces in a file.
     */
    virtual QCString trNamespaces()
    { return decode( "������������ ����" ); }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990728
//////////////////////////////////////////////////////////////////////////

    /*! This is put at the bottom of a class documentation page and is
     *  followed by a list of files that were used to generate the page.
     */
    virtual QCString trGeneratedFromFiles(ClassDef::CompoundType compType,
        bool single)
    { // here s is one of " Class", " Struct" or " Union"
      // single is true implies a single file
      QCString result=(QCString)"���������� � �������� ������ ";
      switch(compType)
      {
        case ClassDef::Class:      result+="�����"; 
          if (single) result+='�'; else result+="��";
          break;
        case ClassDef::Struct:     result+="��������"; 
          if (single) result+='�';
          break;
        case ClassDef::Union:      result+="����������";
          if (single) result+='�'; else result+='�';
          break;
        case ClassDef::Interface:  result+="���������";
          if (single) result+='�'; else result+="��";
          break;
        case ClassDef::Exception:  result+="���������";
          if (single) result+='�'; else result+='�';
          break;
      }
      result+=" ��������� � ����";
      if (single) result+="�:"; else result+="��:";
      return decode(result);
    }

    /*! This is in the (quick) index as a link to the alphabetical compound
     * list.
     */
    virtual QCString trAlphabeticalList()
    { return decode("���������� ���������"); }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990901
//////////////////////////////////////////////////////////////////////////

    /*! This is used as the heading text for the retval command. */
    virtual QCString trReturnValues()
    { return decode("������������ ��������"); }

    /*! This is in the (quick) index as a link to the main page (index.html)
     */
    virtual QCString trMainPage()
    { return decode("��������� ��������"); }

    /*! This is used in references to page that are put in the LaTeX 
     *  documentation. It should be an abbreviation of the word page.
     */
    virtual QCString trPageAbbreviation()
    { return decode("���."); }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-991106
//////////////////////////////////////////////////////////////////////////

    virtual QCString trSources()
    {
      return decode("�������� ������.");
    }
    virtual QCString trDefinedAtLineInSourceFile()
    {
      return decode("��. ����������� � ����� @1 ������ @0");
    }
    virtual QCString trDefinedInSourceFile()
    {
      return decode("��. ����������� � ����� @0");
    }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-991205
//////////////////////////////////////////////////////////////////////////

    virtual QCString trDeprecated()
    {
      return decode("���.");
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.0.0
//////////////////////////////////////////////////////////////////////////

    /*! this text is put before a collaboration diagram */
    virtual QCString trCollaborationDiagram(const char *clName)
    {
      return (QCString)decode("���� ������ ������ ")+clName+":";
    }
    /*! this text is put before an include dependency graph */
    virtual QCString trInclDepGraph(const char *fName)
    {
      return decode("���� ���������� ������������ ������ ��� ")+fName+":";
    }
    /*! header that is put before the list of constructor/destructors. */
    virtual QCString trConstructorDocumentation()
    {
      return decode("�����������(�)"); 
    }
    /*! Used in the file documentation to point to the corresponding sources. */
    virtual QCString trGotoSourceCode()
    {
      return decode("��. �������� ������.");
    }
    /*! Used in the file sources to point to the corresponding documentation. */
    virtual QCString trGotoDocumentation()
    {
      return decode("��. ������������.");
    }
    /*! Text for the \\pre command */
    virtual QCString trPrecondition()
    {
      return decode("�����������");
    }
    /*! Text for the \\post command */
    virtual QCString trPostcondition()
    {
      return decode("�����������");
    }
    /*! Text for the \\invariant command */
    virtual QCString trInvariant()
    {
      return decode("���������");
    }
    /*! Text shown before a multi-line variable/enum initialization */
    virtual QCString trInitialValue()
    {
      return decode("�������������");
    }
    /*! Text used the source code in the file index */
    virtual QCString trCode()
    {
      return decode("�������� ������");
    }
    virtual QCString trGraphicalHierarchy()
    {
      return decode("�������� �������. ����������� ���.");
    }
    virtual QCString trGotoGraphicalHierarchy()
    {
      return decode("��. ����������� ���.");
    }
    virtual QCString trGotoTextualHierarchy()
    {
      return decode("��. ��������� ���.");
    }
    virtual QCString trPageIndex()
    {
      return decode("���������� ��������� ������������ ��������");
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.1.0
//////////////////////////////////////////////////////////////////////////
    
    virtual QCString trNote()
    {
      return decode("�������");
    }
    virtual QCString trPublicTypes()
    {
      return decode("�������� ����");
    }
    virtual QCString trPublicAttribs()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return decode( "���� ������" );
      }
      else
      {
        return decode( "�������� ��������" );
      }
    }
    virtual QCString trStaticPublicAttribs()
    {
      return decode("����������� �������� ������");
    }
    virtual QCString trProtectedTypes()
    {
      return decode("���������� ����");
    }
    virtual QCString trProtectedAttribs()
    {
      return decode("���������� ������");
    }
    virtual QCString trStaticProtectedAttribs()
    {
      return decode("����������� ���������� ������");
    }
    virtual QCString trPrivateTypes()
    {
      return decode("�������� ����");
    }
    virtual QCString trPrivateAttribs()
    {
      return decode("�������� ������");
    }
    virtual QCString trStaticPrivateAttribs()
    {
      return decode("�������� ����������� ������");
    }


//////////////////////////////////////////////////////////////////////////
// new since 1.1.3
//////////////////////////////////////////////////////////////////////////

    /*! Used as a marker that is put before a todo item */
    virtual QCString trTodo()
    /*??*/
    {
      return decode("���������� �������");
    }
    /*! Used as the header of the todo list */
    virtual QCString trTodoList()
    /*??*/
    {
      return decode("������ �����");
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.1.4
//////////////////////////////////////////////////////////////////////////

    virtual QCString trReferencedBy()
    {
      return decode("������������ �");
    }
    virtual QCString trRemarks()
    {
      return decode("����.");
    }
    virtual QCString trAttention()
    {
      return decode("��������");
    }
    virtual QCString trInclByDepGraph()
    {
      return decode("���� ������, � ������� ���������� ���� ����:");
    }
    virtual QCString trSince()
    /*??*/
    {
      return decode("������� �");
    }
    
//////////////////////////////////////////////////////////////////////////
// new since 1.1.5
//////////////////////////////////////////////////////////////////////////

    /*! title of the graph legend page */
    virtual QCString trLegendTitle()
    {
      return decode("�������");
    }
    /*! page explaining how the dot graph's should be interpreted */
    virtual QCString trLegendDocs()
    {
      return decode( 
        "�����������, ������������ � ������.<p>\n"
        "���������� ��������� ������:\n"
        "\\code\n"
        "/*! ��������� ����� ��-�� �������� */\n"
        "class Invisible { };\n\n"
        "/*! ��������� �����, ��������� ������������ ������ */\n"
        "class Truncated : public Invisible { };\n\n"
        "/* ������������������� ����� */\n"
        "class Undocumented { };\n\n"
        "/*! �������� ������������ */\n"
        "class PublicBase : public Truncated { };\n\n"
        "/*! ������ ������ */\n"
        "template<class T> class Templ {};\n\n"
        "/*! ���������� ������������ */\n"
        "class ProtectedBase { };\n\n"
        "/*! �������� ������������ */\n"
        "class PrivateBase { };\n\n"
        "/*! �����, ������������ ������� Inherited */\n"
        "class Used { };\n\n"
        "/*! �����, ����������� �� ������ ������� */\n"
        "class Inherited : public PublicBase,\n"
        "                  protected ProtectedBase,\n"
        "                  private PrivateBase,\n"
        "                  public Undocumented,\n"
        "                  public Templ<int>\n"
        "{\n"
        "  private:\n"
        "    Used *m_usedClass;\n"
        "};\n"
        "\\endcode\n"
        "���� \\c MAX_DOT_GRAPH_HEIGHT � ���������������� ����� "
        "���������� � 240, ��������� ��������� ����:"
        "<p><center><img src=\"graph_legend.gif\"></center>\n"
        "<p>\n"
        "�������������� � ���� ����� ����� ��������� ��������:\n"
        "<ul>\n"
        "<li>����������� ������ ������������� ������������ ��������� ��� �����, "
        "��� �������� ������ ����.\n"
        "<li>������������� � ������ �������� ���������� ����������������� ��������� ��� �����.\n"
        "<li>������������� � ����� �������� ���������� ������������������� ��������� ��� �����.\n"
        "<li>������������� � ������� �������� ���������� ����������������� ��������� ��� �����, ��� ��������\n"
        " �� ��� ��������� ������������/���������� ��������. ���� ������, "
        "���� �� �� ���������� � ��������� ��������.\n"
        "</ul>\n"
        "������� ����� ��������� ��������:\n"
        "<ul>\n"
        "<li>���������� ������� ������������ ��� ����������� ��������� ��������� ������������ "
        "����� ����� ��������.\n"
        "<li>������������ ������� ������������ ��� ���������� ������������.\n"
        "<li>������������ ������� ������������ ��� �������� ������������.\n"
        "<li>���������� ������� ������������, ���� ����� ���������� �"
        "������ ����� ��� ������������ ������ �������."
        "�� �������� ����������� ����������, "
        "����� ������� �������� ����������� ����� ��� ���������. \n"
        "<li>������ ������� ������������ ��� ����� ����������� ������� � "
        "�������, �� ������ �������� ��� ����������� ���������. � ��������"
        "����������� �������� �����������.\n"
        "</ul>\n");
    }
    /*! text for the link to the legend page */
    virtual QCString trLegend()
    {
      return decode("��. �������");
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.0
//////////////////////////////////////////////////////////////////////////
    
    /*! Used as a marker that is put before a test item */
    virtual QCString trTest()
    {
      return decode("����");
    }
    /*! Used as the header of the test list */
    virtual QCString trTestList()
    {
      return decode("������ ������");
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.1
//////////////////////////////////////////////////////////////////////////

    /*! Used as a section header for KDE-2 IDL methods */
    virtual QCString trDCOPMethods()
    {
      return decode("DCOP ������");
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.2
//////////////////////////////////////////////////////////////////////////

    /*! Used as a section header for IDL properties */
    virtual QCString trProperties()
    {
      return decode("��������");
    }
    /*! Used as a section header for IDL property documentation */
    virtual QCString trPropertyDocumentation()
    {
      return decode("������ ������ �������");
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.4
//////////////////////////////////////////////////////////////////////////

    /*! Used for Java interfaces in the summary section of Java packages */
    virtual QCString trInterfaces()
    {
      return decode("����������");
    }
    /*! Used for Java classes in the summary section of Java packages */
    virtual QCString trClasses()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return decode( "��������� ������" );
      }
      else
      {
        return decode( "������" );
      }
    }
    /*! Used as the title of a Java package */
    virtual QCString trPackage(const char *name)
    {
      return decode("����� ")+name;
    }
    /*! Title of the package index page */
    virtual QCString trPackageList()
    {
      return decode("������ ������ ������� ");
    }
    /*! The description of the package index page */
    virtual QCString trPackageListDescription()
    {
      return decode("������ ������ ����������������� �������.");
    }
    /*! The link name in the Quick links header for each page */
    virtual QCString trPackages()
    {
      return decode("������");
    }
    /*! Used as a chapter title for Latex & RTF output */
    virtual QCString trPackageDocumentation()
    {
      return decode("������");
    }
    /*! Text shown before a multi-line define */
    virtual QCString trDefineValue()
    {
      return decode("����������������:");
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.5
//////////////////////////////////////////////////////////////////////////
    
    /*! Used as a marker that is put before a \\bug item */
    virtual QCString trBug()
    {
      return decode("������");
    }
    /*! Used as the header of the bug list */
    virtual QCString trBugList()
    {
      return decode("������");
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.6
//////////////////////////////////////////////////////////////////////////
    /*! Used as ansicpg for RTF file */
    virtual QCString trRTFansicp()
    {
      return "1251";
    }
    /*! Used as ansicpg for RTF fcharset */
    virtual QCString trRTFCharSet()
    {
      return "204";
    }
    /*! Used as header RTF general index */
    virtual QCString trRTFGeneralIndex()
    {
      return decode("���������� ���������");
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trClass(bool first_capital, bool singular)
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        QCString result((first_capital ? "��������� ������" : "��������� ������"));
        return decode(result); 
      }
      else
      {
        QCString result((first_capital ? "�����" : "�����"));
        if(!singular) result+="�";
        return decode(result); 
      }
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trFile(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "����" : "����"));
      if (!singular)  result+="�";
      return decode(result); 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trNamespace(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "�����������" : "�����������"));
      result+=(singular?"� ����":"� ����");
      return decode(result); 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trGroup(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "�����" : "�����"));
      result+=(singular ? "�" : "�");
      return decode(result); 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trPage(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "�������" : "�������"));
      result+=(singular ? "�" : "�");
      return decode(result); 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trMember(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "����" : "����"));
      if (!singular)  result+="�";
      return decode(result); 
    }
   
    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trField(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "���" : "���"));
      result+=(singular ? "�" : "�");
      return decode(result); 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trGlobal(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "���������" : "���������"));
      result+=(singular ? "�" : "�");
      return decode(result); 
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.7
//////////////////////////////////////////////////////////////////////////

    /*! This text is generated when the \\author command is used and
     *  for the author section in man pages. */
    virtual QCString trAuthor(bool first_capital, bool singular)
    {                                                                         
      QCString result((first_capital ? "�����" : "�����"));
      if (!singular) result+="�";
      return decode(result); 
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.11
//////////////////////////////////////////////////////////////////////////

    /*! This text is put before the list of members referenced by a member
     */
    virtual QCString trReferences()
    {
      return "������������ ������";
    }

};

#endif
