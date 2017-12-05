//Lab #2 || Alexa Summers

#include "lab2_RecordManager.hpp"
#include <iostream>
using namespace std;

void Test1 ()
{
    cout << endl << "----------------------------------------" << endl;
    cout << "TEST 1: Open one file and write to it. " << endl << endl;
    RecordManager record;
    record.OpenOutputFile ( "Test1.txt");

    record.DisplayAllOpenFiles();

    record.WriteToFile ("Test1.txt", "Hello, world! " );

    record.CloseOutputFile ( "Test1.txt" );

    cout << endl << "END OF TEST 1." << endl;
}

void Test2()
{
    cout << endl << "---------------------------------------" << endl;
    cout << " TEST 2: Open 5 files and write to them. " << endl << endl;

    RecordManager record;
    record.OpenOutputFile ( "Test2_A.txt" );
    record.OpenOutputFile ( "Test2_B.txt" );
    record.OpenOutputFile ( "Test2_C.txt" );
    record.OpenOutputFile ( "Test2_D.txt" );
    record.OpenOutputFile ( "Test2_E.txt" );

    record.DisplayAllOpenFiles();

    record.WriteToFile ( "Test2_A.txt", "ABCDE" );
    record.WriteToFile ( "Test2_B.txt", "FGHIJ" );
    record.WriteToFile ( "Test2_C.txt", "KLMNO" );
    record.WriteToFile ( "Test2_D.txt", "PQRST" );
    record.WriteToFile ( "Test2_E.txt", "UVWXYZ" );

    record.CloseOutputFile ( "Test2_A.txt" );
    record.CloseOutputFile ( "Test2_B.txt" );
    record.CloseOutputFile ( "Test2_C.txt" );
    record.CloseOutputFile ( "Test2_D.txt" );
    record.CloseOutputFile ( "Test2_E.txt" );

    cout << endl << "END OF TEST 2. " << endl;
}

void Test3()
{
    cout << endl << "----------------------------------------" << endl;
    cout << "TEST 3: Write to a file that isn't opened. " << endl << endl;
    RecordManager record;
    record.DisplayAllOpenFiles();
try
{
    record.WriteToFile( "Test2.txt", "How are you today?" );
}
    catch (runtime_error& ex)
    {
        cout << "Error: " << ex.what() << endl;
    }
    cout << endl << "END OF TEST 3" <<  endl;
}

void Test4()
{
    cout << endl << "--------------------------------------------------" << endl;
    cout << "TEST 4: Close a file that isn't opened. " << endl << endl;
    RecordManager record;
    record.DisplayAllOpenFiles();
try
{
    record.CloseOutputFile( "Test3.txt" );
}
    catch (runtime_error& ex)
    {
        cout << "Error: " << ex.what() << endl;
    }
    cout << endl << "END OF TEST 4. " << endl;
}

void Test5()
{
    cout << endl << "--------------------------------------------------" << endl;
    cout << "TEST 5: Try to open more than the max number of files. " << endl << endl;
    RecordManager record;
try{
    record.OpenOutputFile( "Test5_A.txt" );
    record.OpenOutputFile( "Test5_B.txt" );
    record.OpenOutputFile( "Test5_C.txt" );
    record.OpenOutputFile( "Test5_D.txt" );
    record.OpenOutputFile( "Test5_E.txt" );
    record.OpenOutputFile( "Test4_A.txt" ); //This is too many
}
    catch (runtime_error& ex)
    {
    cout << "Error: " << ex.what() << endl << endl;
    }

    cout << "END OF TEST 5. " << endl;
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

RecordManager::~RecordManager()
{
    for ( int i = 0; i < MAX_FILES; i++ )
    {
        if (m_outputs[i].is_open() )
        {
            m_outputs[i].close();
        }
    }
}


void RecordManager::OpenOutputFile( string filename )
{
    int index = FindAvailableFile();
        if ( index == -1)
        {
            throw runtime_error ("No available files. ");
        }
    m_outputs[ index ].open( filename );
    m_filenames [ index ] = filename;
}

void RecordManager::CloseOutputFile ( string filename )
{
    int index = FindFilenameIndex ( filename );
     if ( index == -1)
        {
            throw runtime_error ("No available files. ");
        }
    m_outputs [ index ].close();
    m_filenames [ index ] = "";
}

void RecordManager:: WriteToFile ( string filename, string text )
{
    int index = FindFilenameIndex ( filename );
    if (index == -1 )
    {
    throw runtime_error ( "No available files." );
    }
    m_outputs [ index ] << text << endl;
}

void RecordManager:: DisplayAllOpenFiles() noexcept
{
    cout << "Open files : " << endl;
    for ( int i = 0; i < MAX_FILES; i++)
    {
        if ( m_outputs[i].is_open() )
        {
            cout << i << ". " << m_filenames[i] << endl;
        }
    }
}

int RecordManager::FindAvailableFile() noexcept
{
    for ( int i = 0; i < MAX_FILES; i++)
    {
        if (m_outputs[i].is_open() == false )
        {
        return i;
        }
    }
    return -1;
}

int RecordManager::FindFilenameIndex ( string filename ) noexcept
{
    for ( int i = 0; i < MAX_FILES; i++ )
    {
        if ( m_filenames[i] == filename )
        {
            return i;
        }
    }
    return -1;
}


