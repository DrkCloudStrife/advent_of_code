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
    REQUIRED_FIELDS = {
        'byr': 'byr:(\d{4})(?=\s|$)',
        'eyr': 'eyr:(\d+)(?=\s|$)',
        'ecl': 'ecl:(\w+)(?=\s|$)',
        'hcl': 'hcl:(#\w+)(?=\s|$)',
        'hgt': 'hgt:(\w+)(?=\s|$)',
        'iyr': 'iyr:(\d+)(?=\s|$)',
        'pid': 'pid:(\d+)(?=\s|$)'
    }

    def __init__(self, data):
        self.passports = []
        self.__reset_valid_passports()
        self.__aggregate_passports(data)

    def validate_pt1(self):
        self.__reset_valid_passports()
        for idx, passport in enumerate(self.passports):
            has_birth_year = "byr" in passport
            has_issue_year = "iyr" in passport
            has_expiration_year = "eyr" in passport
            has_height = "hgt" in passport
            has_hair_color = "hcl" in passport
            has_eye_color = "ecl" in passport
            has_passport_id = "pid" in passport
            has_country_id = "cid" in passport

            is_valid = (
                has_birth_year and
                has_issue_year and
                has_expiration_year and
                has_height and
                has_hair_color and
                has_eye_color and
                has_passport_id
            )

            if is_valid:
                self.valid_passports.append(passport)

    def validate_pt2(self):
        self.__reset_valid_passports()
        for passport in self.passports:
            validity = []
            for key in list(self.REQUIRED_FIELDS):
                is_valid = self.__validate(key, passport)
                print(is_valid)
                validity.append(is_valid)
            # if all validity fields are true
            # Add to `valid_passports`

    def __aggregate_passports(self, data):
        current_passport = ""

        for row in data:
            if row.strip() is '':
                self.passports.append(current_passport.strip())
                current_passport = ""
                continue
            current_passport += row.strip() + ' '

        self.passports.append(current_passport.strip())

    def __validate_byr(self,value):
        print('TBD BYR')

    def __validate_eyr(self,value):
        print('TBD eyr')

    def __validate_ecl(self,value):
        print('TBD ecl')

    def __validate_hcl(self,value):
        print('TBD hcl')

    def __validate_hgt(self,value):
        print('TBD hgt')

    def __validate_iyr(self,value):
        print('TBD iyt')

    def __validate_pid(self,value):
        print('TBD pid')

    def __validate(self, field, pattern):
        reg = self.REQUIRED_FIELDS[field]
        value = re.compile(r'{}'.format(reg))
        validator = getattr(self,'_PasswordValidator__validate_{}'.format(field))
        return validator(value)

    def __reset_valid_passports(self):
        self.valid_passports = []
