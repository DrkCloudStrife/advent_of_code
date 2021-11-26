class PasswordValidator(object):
    BIRTH_YEAR = 'byr:(\d+)(?=\s|$)'
    ISSUE_YEAR = 'iyr:(\d+)(?=\s|$)'
    EXPIRATION_YEAR = 'eyr:(\d+)(?=\s|$)'
    HEIGHT = 'hgt:(\w+)(?=\s|$)'
    HAIR_COLOR = 'hcl:(#\w+)(?=\s|$)'
    EYE_COLOR = 'ecl:(\w+)(?=\s|$)'
    PASSPORT_ID = 'pid:(\d+)(?=\s|$)'
    COUNTRY_ID = 'cid:(\d+)(?=\s|$)'

    def __init__(self, data):
        self.passports = []
        self.__reset_valid_passports()
        self.__aggregate_passports(data)

    def validate_pt1(self):
        self.__reset_valid_passports()
        for passport in self.passports:
            print(passport)

    def __aggregate_passports(self, data):
        current_passport = ""

        for row in data:
            if row.strip() is '':
                self.passports.append(current_passport.strip())
                current_passport = ""
                continue
            current_passport += row.strip() + ' '

        self.passports.append(current_passport.strip())

    def __reset_valid_passports(self):
        self.valid_passports = []
