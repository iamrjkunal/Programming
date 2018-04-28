#!/bin/bash

# Here are some embedded Python examples using Python3.
# They are put into functions for separation and clarity.


# Simple usage, only using python to print the date.
# This is not really a good example, because the `date`
# command works just as well.
function date_time {
    python3 - <<END
from datetime import datetime
print('Current date:')
print(datetime.now())
END
}
# Call the python code.
date_time

# Sending a variable to Python from BASH
function env_args {
    # Put an environment arg into Python.
    # Must be on the same line as the command.
    TESTARG="My Value" python3 - <<END
from os import environ
print('Your environment arg: {}'.format(environ.get('TESTARG', 'missing!')))
END
}
env_args

# Retrieve output from Python and put it into a BASH variable.
# This uses a subshell to retrieve whatever python prints out.
function val_from_python {
    # Get a python value from BASH.
    pythonval="$(python3 - <<END
import os
print('cwd: {}'.format(os.getcwd()))
END
)"
    echo "Python value is: $pythonval"
}
val_from_python

# You can put small python snippets directly into your shell files.
# Here's an example using `urllib` to download some html, and then
# using it in BASH. 

# (granted that you could do this in Python itself,
#  or you could write it all in BASH, but this is just an example.)
function python_power {
    # Grab the html from python.org's PEP8 page and save it to a bash variable.
    # On error, the output will be a basic HTML page with the error message.
    local pythonval="$(python3 - <<END
from urllib import request
try:
    resp = request.urlopen('http://legacy.python.org/dev/peps/pep-0008/')
    data = resp.read().decode('utf-8')
    print(data)
except Exception as ex:
    print("""
        <html>\n<head>\n<title>Error in python_power</title>\n</head>\n
        <body>\nThere was an error retrieving that page: {}\n</body>
""".format(ex))
END
)"
    # Print the content so it can be used by other commands.
    # (you also could've saved it to a global variable.)
    echo $pythonval
}

# Direct the output of this python function to a file.
# The html will not be styled correctly, because no css files are downloaded.
# But the point here is that you can have the full power of python without
# writing separate scripts. Small python snippets can be embedded and used
# from BASH itself.
outfile='pep8.html'
python_power > $outfile
if [[ -f $outfile ]]; then
    echo "New file was created: $outfile"
    google-chrome $outfile
else
    echo "Unable to create new file: $outfile"
fi

