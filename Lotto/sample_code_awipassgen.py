# Created on: 26.06.2014
# Author: mur/gu

# added 2015-08-04 gu v 0.0-rev11-00-gu
# changed 2015-08-11 gu v 0.0-rev12-00-gu
# changed 2015-10-14 gu v 0.0-rev13-00-gu
# changed 2015-11-12 gu v 0.0-rev14-00-gu
# changed 2016-06-29 gu v 0.0-rev15-00-gu

# Versions numbering
awiPassGen_Version = 15

#version history
#2014-06-26 v 0.0-rev00-00 mur: base function created
#2014-06-30 v 0.0-rev01-00 gu: ga-ticket #219 implementation
#2014-07-01 v 0.0-rev02-00 gu: ga-ticket #219 write the customer and partner passwords into config
#2014-07-03 v 0.0-rev03-00 gu: ga-ticket #219 append contents to config file, output information changed
#2014-07-04 v 0.0-rev04-00 gu: ga-ticket #219 bug fix append contents to config file
#2014-08-07 v 0.0-rev05-00 gu: ga-ticket #219 device id must be given, otherwise error message and exit the program
#2015-03-26 v 0.0-rev06-00 gu: ga-ticket #344 not coded customer and partner passwords are written to a normal txt file
#2015-03-27 v 0.0-rev07-00 gu: ga-ticket #344 bug fix not coded customer and partner password written to normal txt file
#2015-04-01 v 0.0-rev08-00 gu: ga-ticket #344 not coded customer and partner password are written to a PDF file
#2015-04-01 v 0.0-rev09-00 gu: code clean, ga-ticket #344 device id appended to the PDF file name; avoid the log file in py2exe (add the line "sys.stderr = sys.stdout" after "import sys")
#2015-05-21 v 0.0-rev10-00 gu: make the default path of the 2 path choose dialog (for encoded and unencoded passwords) to /media/groups/awite/data/gasanalyse/projekte; bug fix when the selected path is none (when user cancel the select path dialog)
#2015-06-30 v 0.0-rev11-00 gu: ga-ticket #343 delete the space character when writing to the end of the line: e.g. 5051 remote5051 a76c1fe3d82749b6d3071a5556871e40 100 "Benutzer" "Customer"
#2015-08-11 v 0.0-rev12-00 gu: ga-ticket #376 second VNC at the same time access
#2015-10-14 v 0.0-rev13-00 gu: * show the awipassgen version number in the gui title
#                              * ga-ticket #376 bugfix, show "N/A" in the pdf report, if the item has not been selected in the multichoice dialog
#                              * ga-ticket #376 bugfix, add a tipp in the multichoice dialog for "Partner VNC", because this choice will only be valid since schema 10.3
#                              * ga-ticket #396 add a boolbox for user to decide if AwiRemote verkaut or AwiRemote fuer interne Zwecke (not finished)
#2015-11-12 v 0.0-rev14-00 gu: * ga-ticket #396 write information automatically into OGo (finised)
#                              * ga-ticket #389 bugfix sometime vnc password does not work
#2016-06-29 v 0.0-rev15-00 gu: * bugfix ga-ticket #468, if less than 3 digital device number, the awiremote port number is not correct any more.

import d3des as d # for brevity - narrow column

def get_vnc_enc( password ):
    passpadd = ( password + '\x00' * 8 )[ :8 ]
    strkey = ''.join( [ chr( x ) for x in d.vnckey ] )
    ekey = d.deskey( strkey, False )
    ctext = d.desfunc( passpadd, ekey )
    return ctext
        
def get_vnc_enc_hex( password ):
    passpadd = ( password + '\x00' * 8 )[ :8 ]
    strkey = ''.join( [ chr( x ) for x in d.vnckey ] )
    ekey = d.deskey( strkey, False )
    ctext = d.desfunc( passpadd, ekey )
    return ctext.encode( 'hex' )
    
if __name__ == '__main__':
    import sys
    sys.stderr = sys.stdout
        
    import hashlib
    import os
    
    # the following variable are for pdf output
    addrVNC = ""
    addrVNC2 = "" # ga-ticket #376 the address of the second VNC access, with 3 digital device number, printed out in the pdf file
    addrPVB = ""
    addrPVB2 = "" # ga-ticket #468 simplified here
    deviceid = -1
    password = "" # password for the first VNC access and for the customer pvb1 access. (First VNC password and customer pvb1 password should be same)
    passwordoem = "" # password for the partner pvb2 access, since ga-ticket #376 the VNC_partner was added (Second VNC password and partner pvb2 password should be same)
    generateLoginCustomer = 0
    generateLoginPartner = 0
    pathAdditional = "enter path"
    
    phrase = "enter phrase"
    phraseoem = "awi"
    deviceid = "0"
    deviceidWithZero = "0" # ga-ticket #468
    path = "enter path"   
    useremote5053 = 0
    useremote5051 = 0
    usevnc = 0
    usevnc2 = 0 # ga-ticket #376
    dochangeconfig = 0
    
    # ga-ticket #396: whether to write information to ogo
    dowritetoogo = 0
    
    # ga-ticket #396: to distinguish whether AwiRemote is for selling or is for intern use
    strAwiRemoteForWhat = ""
    
    if len( sys.argv ) > 3:
        deviceid = sys.argv[ 1 ]
        phrase = sys.argv[ 2 ]
        path = sys.argv[ 3 ]

    else:
        import easygui
        print "usage: %s <deviceid> <password>" % sys.argv[ 0 ]
        
        msg = "Enter password information"
        title = "AwiPassGen (Version %d)" % awiPassGen_Version
        
        # the options in multichoicebox
        fieldremote5051 = "Kunde: remote5051 (PVB 1)"
        fieldremote5053 = "Partner: remote5053 (PVB 2)"
        fieldvnc = "Kunde: VNC"
        fieldvnc2 = "Partner: VNC (Hinweis: Erst ab Schema 10.3)" # ga-ticket #376
        fieldchangeconfig = "write to config"
        fieldwritetoogo = "write to ogo" # ga-ticket #396
        
        fieldNames  = [fieldvnc, fieldvnc2, fieldremote5051, fieldremote5053, fieldchangeconfig, fieldwritetoogo] # ga-ticket #376 add fieldvnc2, ga-ticket #396 add fieldwritetoogo
        fieldValues = []  # we start with blanks for the values
        fieldValues = easygui.multchoicebox( msg, title, fieldNames )
                
        # make sure that none of the fields was left blank
        while 1:  # do forever, until we find acceptable values and break out
            if fieldValues == None:
                break
            errmsg = ""
            
            if errmsg == "":
                break # no problems found
            
        print ("Reply was:", fieldValues)

        # according to the choice from the multichoicebox, set the boolean variables     
        if fieldchangeconfig in fieldValues:
            dochangeconfig = 1
        if fieldremote5051 in fieldValues:
            useremote5051 = 1
        if fieldremote5053 in fieldValues:
            useremote5053 = 1
        if fieldvnc in fieldValues:
            usevnc = 1
        if fieldvnc2 in fieldValues:
            usevnc2 = 1
        if fieldwritetoogo in fieldValues:
            dowritetoogo = 1
            
        if dowritetoogo == 1:
            # ga-ticket #396
            message = "Bitte auswaehlen, AwiRemote verkauft oder fuer interne Zwecke."
            if easygui.boolbox(message, title, ["AwiRemote verkauft", "AwiRemote fuer interne Zwecke"]):
                strAwiRemoteForWhat = "AwiRemote verkauft"
            else:
                strAwiRemoteForWhat = "AwiRemote fuer interne Zwecke"
            print strAwiRemoteForWhat

        # the static text in multienterbox
        fielddeviceid = "Device ID"
        fieldphrasecustomer = "Kunde pvB/VNC"
        fieldphraseoem = "Partner pvB/VNC" # ga-ticket #376 "/VNC" added. # before was: fieldphraseoem = "Partner pvB  (Default: awi)"
    
        if fieldremote5053 in fieldValues or fieldvnc2 in fieldValues:
            fieldNames = [ fielddeviceid, fieldphrasecustomer, fieldphraseoem ]
            fieldValues = [ "", "", "" ] # before was: fieldValues = [ "", "", "awi" ]
          
        else:
            fieldNames = [ fielddeviceid, fieldphrasecustomer ]
            fieldValues = [ "", "" ]  # we start with blanks for the values
 
        # make sure that none of the fields was left blank
        while 1:
            if fieldValues == None:
                break
                
            errmsg = ""

            #for i in range( len( fieldNames ) ):
            if fieldValues[ 0 ].strip() == "":
                errmsg = errmsg + ( 'Hint: Device ID is a required field.' )
                    
            if errmsg == "":
                break # no problems found
                
            fieldValues = easygui.multenterbox( errmsg, title, fieldNames, fieldValues )
            print "Reply was:", fieldValues

            dogeneratepassword = 1

            for i in range( len( fieldValues ) ):
                if i == 0:
                    deviceid = fieldValues[ 0 ]
                    if fieldValues[ 0 ].strip() == "":
                        dogeneratepassword = 0
                if i == 1:
                    phrase = fieldValues[ 1 ]
                    if fieldValues[ 1 ].strip() == "":
                        doWithDeviceIDCustomer = 1 # if this one is 1, use only device id to generate the password, if is 0, use the customer input content to generate the password
                    else:
                        doWithDeviceIDCustomer = 0
                if i == 2:
                    phraseoem = fieldValues[ 2 ]
                    if fieldValues[ 2 ].strip() == "":
                        doWithDeviceIDPartner = 1 # if this one is 1, use only device id to generate the password, if is 0, use the partner input content to generate the password
                    else:
                        doWithDeviceIDPartner = 0

            # ga-ticket #468
            deviceidWithZero = deviceid
            while len(deviceidWithZero) < 4:
                deviceidWithZero = "0" + deviceidWithZero
                                        
            if dogeneratepassword == 1:   
                
                if dochangeconfig == 1:
                        
                    path = easygui.diropenbox("Pfad fuer verschluesselte Passwoerter/path for coded passwords", "", "Z:/awite/data/gasanalyse/projekte")
                    print "selected path to save the encoded passwords: %s" % path
                    
                    pathAdditional = easygui.diropenbox("Pfad fuer unverschluesselte Passwoerter/path for not coded passwords", "", "Z:/awite/data/gasanalyse/projekte")
                    print "selected path to save the not encoded passwords: %s" % pathAdditional

                    #if path <> "enter path" and pathAdditional <> "enter path":
                    if usevnc == 1 or usevnc2 == 1:  # ga-ticket #376
                        if usevnc == 1:
                            if doWithDeviceIDCustomer == 1:
                                # encode the device id with md5, get special 4 hex numbers for a part of the password of custom and OEM
                                deviceidmd5 = hashlib.md5( deviceid ).hexdigest()
                                passwordaddon = deviceidmd5[ 0 ] + deviceidmd5[ 8 ] + deviceidmd5[ 16 ] + deviceidmd5[ 31 ]

                                print "Device ID: %s" % deviceid
                                print "Phrase: %s" % phrase
                                print "Customer Password Addon: %s" % passwordaddon
                                password = phrase + passwordaddon
                                print "Password: %s" % password
                                    
                                # encode the VNC password, show it with hash code and Hex numbers   
                                vnchash = get_vnc_enc( password )
                                vnchex = get_vnc_enc_hex( password )
                                print "VNC hash: %s" % vnchash
                                print "VNC hash in hex: %s" % vnchex
                            else:
                                password = phrase
                                vnchash = get_vnc_enc( password )
                                print "VNC user self defined: %s" % vnchash
                                
                            # write the VNC password to files (user has input the path)
                            vncfilename = "pw"
                            
                            if path is not None:
                                vncfilefullpath = path + "/vnc/" + vncfilename
                                
                                # if there is already the folder "config/vnc/", then wirte the vnc password into pw file,
                                # if there is not such folder, create the folder vnc/
                                if os.path.exists( path + "/vnc/" ):
                                    fp = open(vncfilefullpath, 'wb') # ga-ticket #389 sometimes vnc password does not work, replace 'w' with 'wb'
                                else:
                                    os.makedirs( path + "/vnc/" )
                                    fp = open(vncfilefullpath, 'wb') # ga-ticket #389 sometimes vnc password does not work, replace 'w' with 'wb'
                                        
                                fp.write( vnchash )
                                fp.close()
                           
                            # ga-ticket #468
                            if len(deviceidWithZero) == 4:
                                addrVNC = "awiremote.dyndns.org:3" + deviceidWithZero
                                                                    
                            generateLoginCustomer = 1

                        if usevnc2 == 1: # ga-ticket #376 added this if usevnc2
                            if doWithDeviceIDPartner == 1:
                                # encode the device id with md5, get special 4 hex numbers for a part of the password of custom and OEM
                                deviceidmd5 = hashlib.md5( deviceid ).hexdigest()
                                passwordaddonoem = deviceidmd5[ 1 ] + deviceidmd5[ 9 ] + deviceidmd5[ 17 ] + deviceidmd5[ 30 ]

                                print "Device ID: %s" % deviceid
                                print "Phrase OEM: %s" % phraseoem
                                print "OEM Password Addon: %s" % passwordaddonoem
                                passwordoem = phraseoem + passwordaddonoem
                                print "OEM Password: %s" % passwordoem
                                    
                                # encode the VNC password, show it with hash code and Hex numbers   
                                vnchashoem = get_vnc_enc( passwordoem )
                                vnchexoem = get_vnc_enc_hex( passwordoem )
                                print "VNC for OEM hash: %s" % vnchashoem
                                print "VNC for OEM hash in hex: %s" % vnchexoem
                            else:
                                passwordoem = phraseoem
                                vnchashoem = get_vnc_enc( passwordoem )
                                print "VNC user self defined: %s" % vnchashoem
                                
                            # write the VNC password to files (user has input the path)
                            vncfilename = "pw_partner"
                            
                            if path is not None:
                                vncfilefullpath = path + "/vnc/" + vncfilename
                                
                                # if there is already the folder "config/vnc/", then wirte the vnc password into pw file,
                                # if there is not such folder, create the folder vnc/
                                if os.path.exists( path + "/vnc/" ):
                                    fp = open(vncfilefullpath, 'wb') # ga-ticket #389 sometimes vnc password does not work, replace 'w' with 'wb'
                                else:
                                    os.makedirs( path + "/vnc/" )
                                    fp = open(vncfilefullpath, 'wb') # ga-ticket #389 sometimes vnc password does not work, replace 'w' with 'wb'
                                        
                                fp.write( vnchashoem )
                                fp.close()
                            
                            # ga-ticket #468
                            if len(deviceidWithZero) == 4:
                                addrVNC2 = "awiremote.dyndns.org:1" + deviceidWithZero
                                
                            generateLoginPartner = 1

                    if useremote5051 == 1 or useremote5053 == 1:
                        # encode the device id with md5, get special 4 hex numbers for a part of the password of custom and OEM
                        deviceidmd5 = hashlib.md5( deviceid ).hexdigest()
                        if useremote5051 == 1:
                            if doWithDeviceIDCustomer == 1:
                                passwordaddon = deviceidmd5[ 0 ] + deviceidmd5[ 8 ] + deviceidmd5[ 16 ] + deviceidmd5[ 31 ]
                                print "Device ID: %s" % deviceid
                                print "Phrase: %s" % phrase
                                print "Customer Password Addon: %s" % passwordaddon
                                password = phrase + passwordaddon
                                print "Password: %s" % password

                                # encode the md5 password for customer, show it with Hex numbers,
                                md5hash = hashlib.md5( password ).hexdigest()
                                print "MD5 hash for customer in hex: %s" % md5hash
                            else:
                                password = phrase
                                md5hash = hashlib.md5( password ).hexdigest()
                                print "MD5 user self defined: %s" % md5hash
                            
                            # ga-ticket #468
                            if len(deviceidWithZero) == 4:
                                addrPVB = "awiremote.dyndns.org:4" + deviceidWithZero
                            
                            generateLoginCustomer = 1
                            
                        if useremote5053 == 1:
                            if doWithDeviceIDPartner == 1:
                                passwordaddonoem = deviceidmd5[ 1 ] + deviceidmd5[ 9 ] + deviceidmd5[ 17 ] + deviceidmd5[ 30 ]
                                print "Device ID: %s" % deviceid                  
                                print "Phrase OEM: %s" % phraseoem
                                print "OEM Password Addon: %s" % passwordaddonoem
                                passwordoem = phraseoem + passwordaddonoem  
                                print "OEM Password: %s" % passwordoem

                                # encode the md5 password for OEM, show it with Hex numbers,
                                md5hashoem = hashlib.md5( passwordoem ).hexdigest()
                                print "MD5 hash for OEM in hex: %s" % md5hashoem
                            else:
                                passwordoem = phraseoem
                                md5hashoem = hashlib.md5( passwordoem ).hexdigest()
                                print "MD5 OEM user self defined: %s" % md5hashoem
                            
                            # ga-ticket #468
                            if len(deviceidWithZero) == 4:
                                addrPVB2 = "awiremote.dyndns.org:5" + deviceidWithZero
                            
                            generateLoginPartner = 1
                            
                        if path is not None:    
                            cfafilesourcefullname = path + "/users/users.cfa"
                            print ".cfa full path: %s" % cfafilesourcefullname
                            cfafiletempfullname = cfafilesourcefullname[:-4] + "temp.cfa"
                            print "temp .cfa full path: %s" % cfafiletempfullname
                            cfafilenewfullname = cfafilesourcefullname[:-4] + "new.cfa"
                            print "new .cfa full path: %s" % cfafilenewfullname
                                
                            # if there is already the folder "config/users/", then wirte the vnc password into users.cfa file,
                            # if there is not such folder, create the folder users/
                            if os.path.exists( path + "/users/" ):
                                if os.path.isfile ( cfafilesourcefullname ):
                                    cfafilesource = open( cfafilesourcefullname, "r" )
                                else:
                                    cfafilesource = open( cfafilesourcefullname, "w+" )
                            else:
                                os.makedirs( path + "/users/" )
                                cfafilesource = open( cfafilesourcefullname, "w+" )         
                               
                            cfafiletemp = open( cfafiletempfullname, "a" )  
                               
                            #search lines which contain "remote5051" or "remote5053"
                            for line in cfafilesource.readlines():
                                if line.find( "remote5051" ) == -1 and line.find( "remote5053" ) == -1:
                                    cfafiletemp.write( line )
                                if line.find("\n") == -1 and line.find("\r") == -1:
                                    cfafiletemp.write("\r\n")
                                   
                            #new user name and password in cfa
                            cfafilenew = open( cfafilenewfullname, "a" )
                            if useremote5051 == 1 and useremote5053 == 0:
                                cfafilenew.write ("5051 remote5051 " + md5hash + " 100 \"Benutzer\" \"Customer\"\n")
                            if useremote5051 == 0 and useremote5053 == 1:
                                cfafilenew.write ("5053 remote5053 " + md5hashoem + " 100 \"Benutzer\" \"OEM\" \"en_GB\"\n")
                            if useremote5051 == 1 and useremote5053 == 1:
                                cfafilenew.write ("5051 remote5051 " + md5hash + " 100 \"Benutzer\" \"Customer\"\n5053 remote5053 " + md5hashoem + " 100 \"Benutzer\" \"OEM\" \"en_GB\"\n")   
                                     
                            #read the new username and password
                            cfafilenew = open( cfafilenewfullname, "r" )
                            readcfa = cfafilenew.read()
                                
                            #append to temp file
                            cfafiletemp.write( readcfa )

                            cfafiletemp = open( cfafiletempfullname, "r" )
                            readtmp = cfafiletemp.read()

                            cfafilesource = open( cfafilesourcefullname, "w" )
                            cfafilesource.write( readtmp )
                                    
                            cfafiletemp.close()
                            cfafilesource.close()
                            cfafilenew.close()
                                                                                
                            #remove the cfa temp file
                            if os.path.exists( cfafiletempfullname ):
                                os.remove( cfafiletempfullname )
                            if os.path.exists( cfafilenewfullname ):
                                os.remove( cfafilenewfullname )
                         
                else: # dochangeconfig = 0
                    pathAdditional = easygui.diropenbox("Pfad fuer unverschluesselte Passwoerter/path for not coded passwords", "", "Z:/awite/data/gasanalyse/projekte")
                    print "selected path for not encoded passwords: %s" % pathAdditional

                    #if pathAdditional <> "enter path":
                        
                    # encode the device id with md5, get special 4 hex numbers for a part of the password of custom and OEM
                    deviceidmd5 = hashlib.md5( deviceid ).hexdigest()
                    if usevnc == 1 or useremote5051 == 1:    
                        passwordaddon = deviceidmd5[ 0 ] + deviceidmd5[ 8 ] + deviceidmd5[ 16 ] + deviceidmd5[ 31 ]
                    if usevnc2 == 1 or useremote5053 == 1:
                        passwordaddonoem = deviceidmd5[ 1 ] + deviceidmd5[ 9 ] + deviceidmd5[ 17 ] + deviceidmd5[ 30 ]
                           
                    if usevnc == 1 or useremote5051 == 1:
                        print "Device ID: %s" % deviceid
                        print "Phrase: %s" % phrase
                        print "Customer Password Addon: %s" % passwordaddon
                        if doWithDeviceIDCustomer == 1:
                            password = phrase + passwordaddon
                        else:
                            password = phrase
                        print "Password: %s" % password
                                    
                    if usevnc2 == 1 or useremote5053 == 1:  
                        print "Device ID: %s" % deviceid
                        print "Phrase OEM: %s" % phraseoem
                        print "OEM Password Addon: %s" % passwordaddonoem
                        if doWithDeviceIDPartner == 1:
                            passwordoem = phraseoem + passwordaddonoem
                        else:
                            passwordoem = phraseoem
                        print "OEM Password: %s" % passwordoem
                            
                    if usevnc == 1:
                        # encode the VNC password, show it with hash code and Hex numbers          
                        vnchash = get_vnc_enc( password )
                        vnchex = get_vnc_enc_hex( password )
                        print "VNC hash: %s" % vnchash
                        print "VNC hash in hex: %s" % vnchex
                       
                        # ga-ticket #468
                        if len(deviceidWithZero) == 4:
                            addrVNC = "awiremote.dyndns.org:3" + deviceidWithZero
                            
                        generateLoginCustomer = 1
                       
                    # ga-ticket #376
                    if usevnc2 == 1:
                        # encode the VNC OEM password, show it with hash code and Hex numbers          
                        vnchashoem = get_vnc_enc( passwordoem )
                        vnchexoem = get_vnc_enc_hex( passwordoem )
                        print "VNC hash: %s" % vnchashoem
                        print "VNC hash in hex: %s" % vnchexoem
                        
                        # ga-ticket #468
                        if len(deviceidWithZero) == 4:
                            addrVNC2 = "awiremote.dyndns.org:1" + deviceidWithZero
                       
                        generateLoginPartner = 1
                            
                    if useremote5051 == 1:
                        # encode the md5 password for customer, show it with Hex numbers,
                        md5hash = hashlib.md5( password ).hexdigest()
                        print "MD5 hash for customer in hex: %s" % md5hash
                        
                        # ga-ticket #468
                        if len(deviceidWithZero) == 4:
                            addrPVB = "awiremote.dyndns.org:4" + deviceidWithZero
                        
                        generateLoginCustomer = 1
                        
                    if useremote5053 == 1:
                        # encode the md5 password for OEM, show it with Hex numbers,
                        md5hashoem = hashlib.md5( passwordoem ).hexdigest()
                        print "MD5 hash for OEM in hex: %s" % md5hashoem
                        
                        # ga-ticket #468
                        if len(deviceidWithZero) == 4:
                            addrPVB2 = "awiremote.dyndns.org:5" + deviceidWithZero
                        
                        generateLoginPartner = 1    
                        
                # show the username and generated password in a text box:
                msg = "awite password generator Results:"
                
                # ga-ticket #376 usevnc2 added        
                if usevnc == 1 and useremote5051 == 0 and useremote5053 == 0 and usevnc2 == 0:
                    easygui.textbox( msg, title, "Passwort: \n" + fieldvnc + ":  " + password + '\n' )   
                if usevnc == 0 and useremote5051 == 1 and useremote5053 == 0 and usevnc2 == 0:
                    easygui.textbox( msg, title, "Passwort: \n" + fieldremote5051 + ":   " + password + '\n' )   
                if usevnc == 0 and useremote5051 == 0 and useremote5053 == 1 and usevnc2 == 0:
                    easygui.textbox( msg, title, "Passwort: \n" + fieldremote5053 + ":   " + passwordoem + '\n' )  
                if usevnc == 1 and useremote5051 == 1 and useremote5053 == 0 and usevnc2 == 0:
                    easygui.textbox( msg, title, "Passwort: \n" + fieldvnc + ":  " + password + '\n' + fieldremote5051 + ":  " + password + '\n' )  
                if usevnc == 1 and useremote5051 == 0 and useremote5053 == 1 and usevnc2 == 0:  
                    easygui.textbox( msg, title, "Passwort: \n" + fieldvnc + ":  " + password + '\n' + fieldremote5053 + ":  " + passwordoem + '\n' )  
                if usevnc == 0 and useremote5051 == 1 and useremote5053 == 1 and usevnc2 == 0:
                    easygui.textbox( msg, title, "Passwort: \n" + fieldremote5051 + ":   " + password + '\n' + fieldremote5053 + ":  " + passwordoem + '\n' )  
                if usevnc == 1 and useremote5051 == 1 and useremote5053 == 1 and usevnc2 == 0:
                    easygui.textbox( msg, title, "Passwort: \n" + fieldvnc + ":  " + password + '\n' + fieldremote5051 + ":  " + password + '\n' + fieldremote5053 + ":  " + passwordoem + '\n' )
                
                if usevnc == 1 and useremote5051 == 0 and useremote5053 == 0 and usevnc2 == 1:
                    easygui.textbox( msg, title, "Passwort: \n" + fieldvnc + ":  " + password + '\n' + fieldvnc2 + ":  " + passwordoem + '\n' )   
                if usevnc == 0 and useremote5051 == 1 and useremote5053 == 0 and usevnc2 == 1:
                    easygui.textbox( msg, title, "Passwort: \n" + fieldremote5051 + ":   " + password + '\n' + fieldvnc2 + ":  " + passwordoem + '\n' )   
                if usevnc == 0 and useremote5051 == 0 and useremote5053 == 1 and usevnc2 == 1:
                    easygui.textbox( msg, title, "Passwort: \n" + fieldremote5053 + ":   " + passwordoem + '\n' + fieldvnc2 + ":  " + passwordoem + '\n' )  
                if usevnc == 1 and useremote5051 == 1 and useremote5053 == 0 and usevnc2 == 1:
                    easygui.textbox( msg, title, "Passwort: \n" + fieldvnc + ":  " + password + '\n' + fieldremote5051 + ":  " + password + '\n' + fieldvnc2 + ":  " + passwordoem + '\n' )  
                if usevnc == 1 and useremote5051 == 0 and useremote5053 == 1 and usevnc2 == 1:  
                    easygui.textbox( msg, title, "Passwort: \n" + fieldvnc + ":  " + password + '\n' + fieldremote5053 + ":  " + passwordoem + '\n' + fieldvnc2 + ":  " + passwordoem + '\n' )  
                if usevnc == 0 and useremote5051 == 1 and useremote5053 == 1 and usevnc2 == 1:
                    easygui.textbox( msg, title, "Passwort: \n" + fieldremote5051 + ":   " + password + '\n' + fieldremote5053 + ":  " + passwordoem + '\n' + fieldvnc2 + ":  " + passwordoem + '\n' )  
                if usevnc == 1 and useremote5051 == 1 and useremote5053 == 1 and usevnc2 == 1:
                    easygui.textbox( msg, title, "Passwort: \n" + fieldvnc + ":  " + password + '\n' + fieldremote5051 + ":  " + password + '\n' + fieldremote5053 + ":  " + passwordoem + '\n' + fieldvnc2 + ":  " + passwordoem + '\n' )

            else: # dogeneratepassword == 0:   
                easygui.msgbox( msg = "Please fill in Device ID", ok_button = "Ok", image = None )

        from reportlab.pdfbase import _fontdata_enc_winansi
        from reportlab.pdfbase import _fontdata_enc_macroman
        from reportlab.pdfbase import _fontdata_enc_standard
        from reportlab.pdfbase import _fontdata_enc_symbol
        from reportlab.pdfbase import _fontdata_enc_zapfdingbats
        from reportlab.pdfbase import _fontdata_enc_pdfdoc
        from reportlab.pdfbase import _fontdata_enc_macexpert
        from reportlab.pdfbase import _fontdata_widths_courier
        from reportlab.pdfbase import _fontdata_widths_courierbold
        from reportlab.pdfbase import _fontdata_widths_courieroblique
        from reportlab.pdfbase import _fontdata_widths_courierboldoblique
        from reportlab.pdfbase import _fontdata_widths_helvetica
        from reportlab.pdfbase import _fontdata_widths_helveticabold
        from reportlab.pdfbase import _fontdata_widths_helveticaoblique
        from reportlab.pdfbase import _fontdata_widths_helveticaboldoblique
        from reportlab.pdfbase import _fontdata_widths_timesroman
        from reportlab.pdfbase import _fontdata_widths_timesbold
        from reportlab.pdfbase import _fontdata_widths_timesitalic
        from reportlab.pdfbase import _fontdata_widths_timesbolditalic
        from reportlab.pdfbase import _fontdata_widths_symbol
        from reportlab.pdfbase import _fontdata_widths_zapfdingbats  
        from reportlab.pdfgen import canvas
        from reportlab.lib.pagesizes import A4, cm, landscape
        from reportlab.lib.styles import getSampleStyleSheet
        from reportlab.platypus import Paragraph, Table, TableStyle, Image
        from reportlab.lib.enums import TA_LEFT, TA_CENTER
        from reportlab.lib import colors
        from reportlab.lib.units import inch
        import reportlab.lib.fonts

        a = Image("logo.jpg")
        a.drawHeight = 2 * inch
        a.drawWidth = 4 * inch

        b = Image("footer.jpg")
        b.drawHeight = 1.5 * inch
        b.drawWidth = 7.5 * inch

        def pdf_head(canvas, headtext):
            canvas.setFont("Helvetica-Bold", 16)
            canvas.drawString(25, 8 * inch, headtext)
            canvas.setFillColor(colors.orange)
            canvas.rect(25, 7.8 * inch, 7.5 * inch, 0.12 * inch, fill = 1, stroke = 0)
            #canvas.line(1 * inch, 10 * inch, 7.5 * inch, 10 * inch)
        
        if pathAdditional is None:
            print "no path for PDF files selected!"
        else:
        
            if generateLoginCustomer == 1:  
                c1 = canvas.Canvas(pathAdditional + "/login-customer-" + deviceid + ".pdf")
                dataHead = [[a]]
                tableHead = Table(dataHead, colWidths = 550, rowHeights = 150, hAlign = 'MIDDLE')
                tableHead.setStyle(TableStyle([
                                       ('INNERGRID', (0, 0), (-1, -1), 0.25, colors.white),
                                       ('BOX', (0, 0), (-1, -1), 0.25, colors.white),
                                       ('BACKGROUND', (0, 0), (-1, 2), colors.white),
                                       ]))
                tableHead.wrapOn(c1, 200, 400)
                tableHead.drawOn(c1, 20, 600)
                
                pdf_head(c1, "Anmeldedaten Kunde/customer login")
                                    
                # ga-ticket #376: show only the selected item
                # ga-ticket #468 simplified here
                if usevnc == 1 and useremote5051 == 1:
                    data=[['VNC\nAdresse/address: ' + str(addrVNC) + '\nPassword: ' + str(password)], ['PVB\nAdresse/address: ' + str(addrPVB) + '\nPassword: ' + str(password)], [b]]
                elif usevnc == 1:
                    data=[['VNC\nAdresse/address: ' + str(addrVNC) + '\nPassword: ' + str(password)], ['PVB\nAdresse/address: N/A \nPassword: N/A'], [b]]
                elif useremote5051 == 1:
                    data=[['VNC\nAdresse/address: N/A \nPassword: N/A'], ['PVB\nAdresse/address: ' + str(addrPVB) + '\nPassword: ' + str(password)], [b]]
                else:
                    print "neither VNC nor PVB1 has been selected"
                    
                table = Table(data, colWidths = 550, rowHeights = 135, hAlign = 'MIDDLE')
                table.setStyle(TableStyle([
                                       ('INNERGRID', (0, 0), (-1, -1), 0.25, colors.white),
                                       ('BOX', (0, 0), (-1, -1), 0.25, colors.white),
                                       ('BACKGROUND', (0, 0), (-1, 2), colors.white),
                                       ('VALIGN', (0, 0), (-1, -1), 'MIDDLE'),
                                       ('FONTSIZE', (0, 0), (-1, -1), 13),
                                       ]))
                                       
                table.wrapOn(c1, 200, 400)
                table.drawOn(c1, 20, 100) # ga-ticket #376 replace 220 with 100
                
                c1.save()
            
            if generateLoginPartner == 1:
                c2 = canvas.Canvas(pathAdditional + "/login-partner-" + deviceid + ".pdf")  
                dataHead = [[a]]
                tableHead = Table(dataHead, colWidths = 550, rowHeights = 150, hAlign = 'MIDDLE')
                tableHead.setStyle(TableStyle([
                                       ('INNERGRID', (0, 0), (-1, -1), 0.25, colors.white),
                                       ('BOX', (0, 0), (-1, -1), 0.25, colors.white),
                                       ('BACKGROUND', (0, 0), (-1, 2), colors.white),
                                       ]))
                tableHead.wrapOn(c2, 200, 400)
                tableHead.drawOn(c2, 20, 600)
                pdf_head(c2, "Anmeldedaten Partner/partner login")
                
                # ga-ticket #376: show only the selected item
                # ga-ticket #468 simplified here
                if usevnc2 == 1 and useremote5053 == 1:
                    data=[['VNC\nAdresse/address: ' + str(addrVNC2) + '\nPassword: ' + str(passwordoem)], ['PVB\nAdresse/address: ' + str(addrPVB2) + '\nPassword: ' + str(passwordoem)], [b]]
                elif usevnc2 == 1:
                    data=[['VNC\nAdresse/address: ' + str(addrVNC2) + '\nPassword: ' + str(passwordoem)], ['PVB\nAdresse/address: N/A \nPassword: N/A'], [b]]
                elif useremote5053 == 1:
                    data=[['VNC\nAdresse/address: N/A \nPassword: N/A'], ['PVB\nAdresse/address: ' + str(addrPVB2) + '\nPassword: ' + str(passwordoem)], [b]]
                else:
                    print "neither VNC2 nor PVB2 has been selected"
                                    
                table = Table(data, colWidths = 550, rowHeights = 135, hAlign = 'MIDDLE')
                table.setStyle(TableStyle([
                                       ('INNERGRID', (0, 0), (-1, -1), 0.25, colors.white),
                                       ('BOX', (0, 0), (-1, -1), 0.25, colors.white),
                                       ('BACKGROUND', (0, 0), (-1, 2), colors.white),
                                       ('VALIGN', (0, 0), (-1, -1), 'MIDDLE'),
                                       ('FONTSIZE', (0, 0), (-1, -1), 13),
                                       ]))
                                       
                table.wrapOn(c2, 200, 400)
                table.drawOn(c2, 20, 100) # ga-ticket #376 replace 220 with 100

                c2.save()

        # ga-ticket #396 write information to OGo database (Postgre Datenbank), only if "write to ogo" has been chosen.
 
        # Both Linux and Window need to install the virtualenv and psycopg2,
        # psycopg 2 is a port of the psycopg python-postgresql database interface.
        
        # Under Linux, it is necessary to execute the following 3 commands, it is needed only once:
        # virtualenv -p /usr/bin/python2.7 sqlenv
        # source sqlenv/bin/activate
        # sudo pip install psycopg2

        # Under Windows
        # install pip: download get-pip.py   python get-pip.py
        # go to Python folder/Script   pip install virtualenv
        # download psycopg2 execute install file from http://www.stickpeople.com/projects/python/win-psycopg/ and install it
        
        if dowritetoogo == 1:
            hostname = '192.168.0.10' # can be 'localhost'
            username = 'OGo' # local test database user name 'bob'
            database_password = 'OGo' # local test database password '12345678'
            database = 'OGo'

            # Simple routine to run a query on a database and print the results:
            def doQueryOGoProjectID(conn) :
                cur = conn.cursor()

                try:
                    # local test database
                    #cur.execute("select measurementunitid, symbol, symbolnameterminus, unit, unitnameterminus FROM measurementunit")

                    #for measurementunitid, symbol, symbolnameterminus, unit, unitnameterminus in cur.fetchall() :
                    #    print measurementunitid, symbol, symbolnameterminus, unit, unitnameterminus
                    #    print '\n'
                    
                    # OGo test database (192.168.0.16)
                    strReturnProjectID = "no ProjectID"
                    
                    strDeviceID = deviceid
                    while len(strDeviceID) < 4:  # ga-ticket #468 change if to while
                        strDeviceID = "0" + strDeviceID     
                    strAfterLike = "'%." + strDeviceID + "%'"
                    strSQLQuery = "SELECT \"public\".\"project\".\"project_id\" from \"public\".\"project\" WHERE \"number\" LIKE " + strAfterLike
                    print strSQLQuery
                    
                    cur.execute(strSQLQuery)
                    strReturnProjectID = cur.fetchone()[0]

                    #for project_id in cur.fetchall():
                    #    print project_id
                    #    print '\n'
                               
                    return strReturnProjectID
                    
                except:
                    print "query failed"
                    return strReturnProjectID
                    
            def doInsert(conn) :
                cur = conn.cursor()
                
                # local test database
                #try:
                #    cur.execute("insert into awivaluetypetranslation (awivaluetype,valuetypeid) values (%s, %s)", ('This is only a test, please delete this line', 5))
                #    print "one line has been inserted into the table"
                #except:
                #    print "insert failed"
                
                conn.commit()
                
            def doUpdate(conn, nProjectID):
                cur = conn.cursor()
                
                strAddressVNCCustomer = "" #VNC1
                strAddressVNCPartner = "" #VNC2
                strAddressPVBCustomer = "" #PVB1
                strAddressPVBCustomer = "" #PVB2
                strPasswordVNCCustomer = "" #VNC1
                strPasswordVNCPartner = "" #VNC2
                strPasswordPVBCustomer = "" #PVB1
                strPasswordPVBPartner = "" #PVB2
                
                # ga-ticket #468 simplified here
                strAddressVNCCustomer = addrVNC
                strAddressVNCPartner = addrVNC2
                strAddressPVBCustomer = addrPVB
                strAddressPVBPartner = addrPVB2
                                    
                if len(strAddressVNCCustomer) > 0:
                    strPasswordVNCCustomer = password
                if len(strAddressVNCPartner) > 0:
                    strPasswordVNCPartner = passwordoem
                if len(strAddressPVBCustomer) > 0:
                    strPasswordPVBCustomer = password
                if len(strAddressPVBPartner) > 0:
                    strPasswordPVBPartner = passwordoem
            
                strSQLUpdate = "UPDATE \"public\".\"hw_location\" SET \"location_option\" = '" + strAwiRemoteForWhat + "', \"location_vnc_kunde\" = '" + strAddressVNCCustomer + " - " + strPasswordVNCCustomer + "', \"location_vnc_partner\" = '" + strAddressVNCPartner + " - " + strPasswordVNCPartner + "', \"location_""pv_kunde\" = '" + strAddressPVBCustomer + " - " + strPasswordPVBCustomer + "', \"location_pv_partner\" = '" + strAddressPVBPartner + " - " + strPasswordPVBPartner + "' WHERE \"location_ogo_project_id\" = " + str(nProjectID)
                print strSQLUpdate
                
                try:
                    cur.execute(strSQLUpdate)
                except:
                    print "update failed"
                    
                conn.commit()
                
            print "Using psycopg2......"
            import psycopg2
            myConnection = psycopg2.connect(host=hostname, user=username, password=database_password, dbname=database)
            nProjectID = doQueryOGoProjectID(myConnection)
            print nProjectID
            
            if nProjectID == "no ProjectID":
                print "Eintrag Passwoerter im OGo nicht moeglich (Seriennummer existiert nicht)"
                easygui.msgbox("Eintrag Passwoerter im OGo nicht moeglich (Seriennummer existiert nicht)", ok_button = "OK")
