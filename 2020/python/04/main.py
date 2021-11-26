import re

class PasswordValidator(object):
    BIRTH_YEAR = 'byr:(\d+)(?=\s|$)'
    COUNTRY_ID = 'cid:(\d+)(?=\s|$)'
    EXPIRATION_YEAR = 'eyr:(\d+)(?=\s|$)'
    EYE_COLOR = 'ecl:(\w+)(?=\s|$)'
    HAIR_COLOR = 'hcl:(#\w+)(?=\s|$)'
    HEIGHT = 'hgt:(\w+)(?=\s|$)'
    ISSUE_YEAR = 'iyr:(\d+)(?=\s|$)'
    PASSPORT_ID = 'pid:(\d+)(?=\s|$)'

    def __init__(self, data):
        self.passports = []
        self.__reset_valid_passports()
        self.__aggregate_passports(data)

    def validate_pt1(self):
        self.__reset_valid_passports()
        for passport in self.passports:
            birth = self.__pattern('BIRTH_YEAR').findall(passport)
            country = self.__pattern('COUNTRY_ID').findall(passport)
            expiration = self.__pattern('EXPIRATION_YEAR').findall(passport)
            eyes = self.__pattern('EYE_COLOR').findall(passport)
            hair = self.__pattern('HAIR_COLOR').findall(passport)
            height = self.__pattern('HEIGHT').findall(passport)
            issued = self.__pattern('ISSUE_YEAR').findall(passport)
            pid = self.__pattern('PASSPORT_ID').findall(passport)

            if birth and expiration and eyes and hair and height and issued and pid:
                self.valid_passports.append(passport)

    def __aggregate_passports(self, data):
        current_passport = ""

        for row in data:
            if row.strip() is '':
                self.passports.append(current_passport.strip())
                current_passport = ""
                continue
            current_passport += row.strip() + ' '

        self.passports.append(current_passport.strip())

    def __pattern(self, pattern_type):
        reg = getattr(self, pattern_type)
        return re.compile(r'{}'.format(reg))

    def __reset_valid_passports(self):
        self.valid_passports = []
