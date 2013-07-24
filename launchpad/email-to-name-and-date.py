#
# Attempt to find a launchpad name  web link and date created  for every email address supplied:
#
#  python email-to-name-and-date.py foo@bar.com blaa@foo.com

import argparse

parser = argparse.ArgumentParser(description='Find infomation by email address')

parser.add_argument('emails', metavar='EMAIL', nargs='+',
                    help='An email address to query')

args = parser.parse_args()

from launchpadlib.launchpad import Launchpad

launchpad = Launchpad.login_with('openstack-dm', 'production')

for email in args.emails:
    try:
        person = launchpad.people.getByEmail(email=email)
        if person:
            print person.name,  email,  person.web_link,    person.date_created.date()
    except:
        continue
